#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct FastFourierTransform {
  using C = complex< double >;

  const double PI = acos(-1);
  vector< vector< C > > rts, rrts;

  void ensure_base(int N) {
    if(rts.size() >= N) return;
    rts.resize(N), rrts.resize(N);
    for(int i = 1; i < N; i <<= 1) {
      if(rts[i].size()) continue;
      rts[i].resize(i), rrts[i].resize(i);
      for(int k = 0; k < i; k++) {
        rts[i][k] = polar(1.0, PI / i * k);
        rrts[i][k] = polar(1.0, -PI / i * k);
      }
    }
  }

  void DiscreteFourierTransform(vector< C > &F, bool rev) {
    const int N = (int) F.size();
    auto &r = rev ? rrts : rts;

    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    ensure_base(N);
    C s, t;
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          s = F[j + k];
          t = C(F[j + k + i].real() * r[i][k].real() - F[j + k + i].imag() * r[i][k].imag(),
                F[j + k + i].real() * r[i][k].imag() + F[j + k + i].imag() * r[i][k].real());
          F[j + k] = s + t, F[j + k + i] = s - t;
        }
      }
    }
    if(rev) for(int i = 0; i < N; i++) F[i] /= N;
  }

  vector< long long > Multiply(const vector< int > &A, const vector< int > &B) {
    int sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< C > F(sz), G(sz);
    for(int i = 0; i < A.size(); i++) F[i] = A[i];
    for(int i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(int i = 0; i < sz; i++) F[i] *= G[i];
    DiscreteFourierTransform(F, true);
    vector< long long > X(A.size() + B.size() - 1);
    for(int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
    return (X);
  }
};

using int64 = long long;

vector< pair< int, int > > S;
FastFourierTransform fft;
int rest[200005];
int64 ans[200005];


void rec(int left, int right) {
  if(left + 1 >= right) {
    return;
  }
  int mid = (left + right) / 2;
  rec(left, mid);
  rec(mid, right);
  vector< int > latte(mid - left), malta(right - mid);
  for(int i = left; i < mid; i++) {
    latte[i - left] = rest[S[i].second];
  }
  reverse(begin(latte), end(latte));
  for(int i = mid; i < right; i++) {
    malta[i - mid] = S[i].first;
  }
  auto beet = fft.Multiply(latte, malta);
  for(int i = 0; i < beet.size(); i++) {
    ans[i + 2] += beet[i];
  }
}

int main() {
  int N, X, A[200000];

  cin >> N >> X;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A[i] = x < X;
  }


  for(int i = 0; i < N; i++) {
    int x = 0;
    for(int j = i; j < N; j++) {
      x += A[j];
    }
  }

  int pv = 0;
  for(int i = N - 1; i >= 0; i--) {
    ++pv;
    if(A[i] == 1) {
      S.emplace_back(pv, i);
      pv = 0;
    }
  }
  reverse(begin(S), end(S));

  pv = 0;
  for(int i = 0; i < N; i++) {
    ++pv;
    if(A[i] == 0) {
      ans[0] += pv;
    } else if(A[i] == 1) {
      rest[i] = pv;
      pv = 0;
    }
  }


  if(S.size()) {
    rec(0, S.size());
    for(int i = 0; i < S.size(); i++) {
      ans[1] += 1LL * S[i].first * rest[S[i].second];
    }
  }
  for(int i = 0; i <= N; i++) cout << ans[i] << " ";
  cout << endl;
}