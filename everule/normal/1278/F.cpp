#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
/*
using ModType = int;
 
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
 
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
struct polynomial{
    vector<Mint> poly;
    polynomial(int n) : poly(n+1,Mint(0)) {}
    polynomial(vector<Mint> seq) : poly(seq) {}
    polynomial operator+(polynomial o){
        polynomial ans(max(size(), o.size()));
        for(int i=0;i<=ans.size();i++){
            ans[i] += (i > size() ? Mint(0) : poly[i]);
            ans[i] += (i > o.size() ? Mint(0) : o[i]);
        }
        return ans;
    }
    polynomial operator-(polynomial o){
        polynomial ans(max(size(), o.size()));
        for(int i=0;i<=ans.size();i++){
            ans[i] += (i > size() ? Mint(0) : poly[i]);
            ans[i] -= (i > o.size() ? Mint(0) : o[i]);
        }
        return ans;
    }
    polynomial operator*(polynomial o){
        polynomial ans(size() + o.size());
        for(int i=0;i<=size();i++){
            for(int j=0;j<=o.size();j++){
                ans[i+j] += poly[i] * o[j];
            }
        }
        return ans;
    }
    void operator+=(polynomial o){
        if(o.size() > size()) poly.reserve(o.size() + 1);
        for(int i=0;i<=o.size();i++){
            poly[i] += o[i];
        }
    }
    void operator-=(polynomial o){
        if(o.size() > size()) poly.reserve(o.size() + 1);
        for(int i=0;i<=o.size();i++){
            poly[i] -= o[i];
        }
    }
    void operator*=(polynomial o){
        polynomial ans(size() + o.size());
        for(int i=0;i<=size();i++){
            for(int j=0;j<=o.size();j++){
                ans[i+j] += poly[i] * o[j];
            }
        }
        poly.swap(ans.poly);
    }
    int size() const{
        return poly.size() - 1;
    }
    template<typename T>
    Mint& operator[](T id){
        int idx = int(id);
        if(idx > size()) poly.resize(idx + 1);
        return poly[idx];
    }
    Mint operator()(Mint val){
        Mint pw = 1;
        Mint ans = 0;
        for(int i=0;i<=size();i++){
            ans += poly[i] * pw;
            pw *= val;
        }
        return ans;
    }
    polynomial(std::initializer_list<Mint> values) : poly(values) {
        reverse(poly.begin(), poly.end());
    }
    polynomial(polynomial &x) : poly(x.poly) {}
    polynomial(Mint x) : poly({x}) {}
    polynomial() : poly({Mint(0)}) {}
};
ostream& operator<<(ostream& out, polynomial &pol){
    for(auto x: pol.poly){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
vector<Mint> fact, invfact;
void computefactorial(int n){
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = i * fact[i-1];
    }
    invfact[n] = 1/fact[n];
    for(int i=n-1;i>=0;--i){
        invfact[i] = (i+1) * invfact[i+1];
    }
}
void solve(){
    Mint n,m,k;
    cin>>n>>m>>k;
    vector<polynomial> poly(int(k+1));
    poly[0] = polynomial({Mint(1)});
    for(int i=1;i<=int(k);i++){
        poly[i] = poly[i-1] * polynomial({Mint(1), Mint(-i+1)});
    }
    vector<Mint> inv(k+1);
    for(Mint i=1;i()<=k();i++){
        inv[int(i)] = 1/i;
    }
    polynomial curr = polynomial(int(k));
    curr[k] = 1;
    Mint ans = 0;
    if(n() < k()){
        Mint x = 1;
        for(int i=0;i<=n();i++){
            ans += x * power(Mint(i),int(k)) * power(1/m, int(i)) * power(1 - 1/m, int(n - i));
            x *= n - i;
            x /= i + 1; 
        }
        cout<<ans<<"\n";
        return;
    }
    for(int i=int(k);i>0;--i){
        Mint x = curr[i];
        curr -= poly[i] * polynomial(curr[i]);
        ans += x * poly[i](n)/power(m,i);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}