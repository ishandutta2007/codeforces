#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template<class T>
T bpow(T x, int y) {
  if (y == 0)
    return T(1);
  if (y % 2)
    return bpow(x, y - 1) * x;
  T v = bpow(x, y / 2);
  return v * v;
}

struct ZP {
  static const int kModulo = 998244353;
  static const int kRoot = 5;

  constexpr ZP(int64_t y = 0): x(y % kModulo) { if (x < 0) x += kModulo; }
  ZP& operator+=(ZP that) { if ((x += that.x) >= kModulo) x -= kModulo; return *this; }
  ZP& operator-=(ZP that) { if ((x -= that.x) < 0) x += kModulo; return *this; }
  ZP& operator*=(ZP that) { x = (int64_t(x) * that.x) % kModulo; return *this; }
  ZP operator+(ZP that) const { return ZP(*this) += that; }
  ZP operator-(ZP that) const { return ZP(*this) -= that; }
  ZP operator*(ZP that) const { return ZP(*this) *= that; }
  ZP operator/(ZP that) const { return *this * that.inv(); }

  ZP operator-() const { return ZP(kModulo - x); }

  ZP inv() const { return bpow(*this, kModulo - 2); }
  static ZP root(int order) { return bpow(ZP(kRoot), (kModulo - 1) / order); }

  explicit operator int() const { return x; }
  explicit operator bool() const { return x; }

  bool operator==(ZP that) const { return x == that.x; }
  bool operator!=(ZP that) const { return x != that.x; }

  int x;
};

ZP fact(size_t n) {
  static vector<ZP> data(1, 1);
  while (data.size() <= n) {
    data.push_back(data.back() * data.size());
  }

  return data[n];
}

ZP inverse(size_t n) {
  static vector<ZP> data(2, 1);
  while (data.size() <= n) {
    int x = data.size();
    const int kModulo = ZP::kModulo;
    data.push_back(data[kModulo % x] * (kModulo - kModulo / x));
  }
  return data[n];
}

ZP ifact(size_t n) {
  static vector<ZP> data(1, 1);
  while (data.size() <= n) {
    data.push_back(data.back() * inverse(data.size()));
  }
  return data[n];
}

static void fft(vector<ZP> &line, bool invert = false) {
  for (size_t i = 1, j = 0; i < line.size(); ++i) {
    int bit = line.size() / 2;
    for (; j & bit; bit /= 2)
      j ^= bit;
    j ^= bit;
    if (i < j)
      swap(line[i], line[j]);
  }

  for (size_t window = 1; window < line.size(); window *= 2) {
    ZP root = ZP::root(window * 2);
    if (invert)
      root = root.inv();

    for (size_t begin = 0; begin < line.size(); begin += 2 * window) {
      ZP w = 1;
      for (size_t i = 0; i < window; ++i, w = w * root) {
        ZP a = line[begin + i];
        ZP b = line[begin + window + i] * w;
        line[begin + i] = a + b;
        line[begin + window + i] = a - b;
      }
    }
  }
}


struct Power {
  size_t exp;
  Power operator^(size_t x) { return Power{exp * x}; }
} X{1};

struct Poly {
  Poly() {}
  Poly(ZP x): A(1, x) {}
  Poly(vector<ZP> A): A(std::move(A)) { clean(); }
  Poly(Power p): A(p.exp + 1, 0) { A[p.exp] = 1; }

  Poly& operator+=(const Poly& that) {
    A.resize(max(A.size(), that.A.size()));
    for (size_t i = 0; i < that.A.size(); ++i)
      A[i] += that.A[i];
    clean();
    return *this;
  }

  Poly& operator-=(const Poly& that) {
    A.resize(max(A.size(), that.A.size()));
    for (size_t i = 0; i < that.A.size(); ++i)
      A[i] -= that.A[i];
    clean();
    return *this;
  }

  Poly operator+(const Poly& that) const { return Poly(*this) += that; }
  Poly operator-(const Poly& that) const { return Poly(*this) -= that; }
  Poly operator-() const { auto B = A; for (auto &x : B) x = -x; return B; }

  Poly operator*(Poly that) const {
    if (A.empty() || that.A.empty()) {
      return Poly();
    }

    vector<ZP> &B = that.A;
    if (min(A.size(), B.size()) < 15) {
      vector<ZP> C(A.size() + B.size() - 1, 0);
      for (size_t i = 0; i < A.size(); ++i)
        for (size_t j = 0; j < B.size(); ++j)
          C[i + j] += A[i] * B[j];
      return C;
    }

    vector<ZP> A = this->A;

    size_t size = 1;
    while (size < A.size() + B.size())
      size *= 2;
    A.resize(size);
    B.resize(size);

    fft(A); fft(B);
    for (size_t i = 0; i < size; ++i)
      A[i] *= B[i];

    fft(A, true);
    for (size_t i = 0; i < size; ++i)
      A[i] *= inverse(size);
    return A;
  }
  Poly& operator*=(const Poly& that) { return (*this = *this * that); }

  Poly& operator*=(Power p) { A.insert(A.begin(), p.exp, 0); return *this; }
  Poly operator*(Power p) const { return Poly(*this) *= p; }

  Poly& operator/=(Power p) { 
    if (A.size() < p.exp) {
      A.clear();
    } else {
      A.erase(A.begin(), A.begin() + p.exp);
    }
    return *this;
  }
  Poly operator/(Power p) const { return Poly(*this) /= p; }

  Poly& operator%=(Power p) { A.resize(min(A.size(), p.exp)); return *this; }
  Poly operator%(Power p) const { return Poly(*this) %= p; }

  Poly& operator*=(ZP x) { for (auto &y : A) y *= x; return *this; }
  Poly operator*(ZP x) const { return Poly(*this) *= x; }

  Poly& operator/=(ZP x) { return *this *= x.inv(); }
  Poly operator/(ZP x) const { return Poly(*this) /= x; }

  Poly deriv(int rank = 1) const { 
    if (degree() + 1 < rank) {
      return Poly();
    }

    vector<ZP> result(degree() + 1 - rank);
    for (int i = rank; i <= degree(); ++i)
      result[i - rank] = fact(i) * ifact(i - rank) * A[i];
    return result;
  }

  Poly integr() const {
    vector<ZP> result(degree() + 2);
    for (int i = 0; i <= degree(); ++i)
      result[i + 1] = A[i] * inverse(i + 1);

    return result;
  }

  Poly log(size_t n) {
    assert(int(A[0]) == 1);
    return (deriv() % (X^n) * inv(n)).integr() % (X^n);
  }

  Poly exp(size_t n) {
    if (n == 1) {
      assert(int((*this)[0]) == 0);
      return ZP(1);
    }

    auto B = exp((n + 1) / 2);
    auto A = *this % (X^n);
    return (B * (Poly(1) + A - B.log(n))) % (X^n);
  }

  Poly inv(size_t n) const {
    if (n == 1)
      return (*this)[0].inv();
    auto B = inv((n + 1) / 2);
    auto A = *this % (X^n);
    return (B * (Poly(2) - A * B)) % (X^n);
  }

  Poly sqrt(size_t n) const {
    if (n == 1) {
      auto x = (*this)[0];
      assert(x == 1); // no code for sqrt of random value 
      return x;
    }

    auto B = sqrt((n + 1) / 2);
    auto A = *this % (X^n);
    return (B + A * B.inv(n)) / 2;
  }

  template<class Init, class Recurse>
  static Poly newton(size_t n, Init init, Recurse recurse) {
    if (n == 1) {
      return ZP(init());
    }

    auto B = newton((n + 1) / 2, init, recurse);
    return recurse(n, std::move(B));
  }

  int degree() const { return A.size() - 1; }

  void clean() {
    while (!A.empty() && !A.back())
      A.pop_back();
  }

  ZP operator[](size_t index) const {
    if (index < A.size())
      return A[index];
    return 0;
  }

  vector<ZP> A;
};

Poly operator+(ZP X, Poly Y) { return Y + X; }
Poly operator-(ZP X, Poly Y) { return Poly(X) - Y; }
Poly operator*(ZP X, Poly Y) { return Y * X; }

int main() {
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;

  vector<ZP> A(M + 1, 0);
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    if (x <= M)
      A[x] = 1;
  }

  Poly AA(A);

  auto recurse = [&](int n, Poly B) {
    auto A = AA % (X^n);
    auto prod = B * A % (X^n);
    auto num = (prod * B - B + ZP(1)) % (X^n);
    auto den = 2 * prod - ZP(1);
    return B - num * den.inv(n) % (X^n);
  };

  auto answer = Poly::newton(M + 1, [&]() { return 1; }, recurse);

  for (int i = 1; i <= M; ++i)
    cout << int(answer[i]) << "\n";
}