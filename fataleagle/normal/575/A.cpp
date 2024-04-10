#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int MAXN = 50005;
ll K, P, S[MAXN], J[MAXN], V[MAXN];
int N, M;

struct matrix {
  ll a, b, c, d;
  // a b
  // c d
  matrix operator*(matrix m){
    return {
      (m.a * a + m.b * c) % P,
      (m.a * b + m.b * d) % P,
      (m.c * a + m.d * c) % P,
      (m.c * b + m.d * d) % P
    };
  }
  matrix pow(ll x){
    if(x == 0) return {1, 0, 0, 1};
    matrix m = this -> pow(x / 2);
    m = m * m;
    if(x % 2) m = m * *this;
    return m;
  }
};

ostream& operator<<(ostream &o, matrix m){
  o << "{" << m.a << ", " << m.b << ", " << m.c << ", " << m.d << "}";
  return o;
}

const int SZ = 1 << 16;
matrix A[2 * SZ];

matrix product(int p, int a, int b, int l, int r){
  if(b < l || r < a) return {1, 0, 0, 1};
  if(l <= a && b <= r) return A[p];
  int m = (a + b) / 2;
  return product(2 * p, a, m, l, r) * product(2 * p + 1, m + 1, b, l, r);
}

void read(){
  ios::sync_with_stdio(0);
  cin >> K >> P >> N;
  for(int i = 0; i < N; i++){
    cin >> S[i];
  }
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> J[i] >> V[i];
  }
}

void build(){
  for(int i = 0; i < N; i++){
    A[SZ + i] = {S[(i + 1) % N], S[i], 1, 0};
  }
  for(int i = SZ - 1; i >= 0; i--){
    A[i] = A[2 * i] * A[2 * i + 1];
  }
}

matrix get(ll l, ll r){
  int lm = int(l % N + 1);
  int rm = int(r % N + 1);
  if(l / N == r / N){
    return product(1, 1, SZ, lm, rm);
  }
  if(l % N != 0){
    ll m = (l / N + 1) * N;
    matrix res = {1, 0, 0, 1};
    res = res * product(1, 1, SZ, lm, N);
    res = res * get(m, r);
    return res;
  }
  if(r % N != N - 1){
    ll m = (r / N) * N - 1;
    matrix res = {1, 0, 0, 1};
    res = res * get(l, m);
    res = res * product(1, 1, SZ, 1, rm);
    return res;
  }
  ll k = r / N - l / N + 1;
  return product(1, 1, SZ, 1, N).pow(k);
}

void reindex(){
  pii tmp[M];
  for(int i = 0; i < M; i++){
    tmp[i] = pii(J[i], V[i]);
  }
  sort(tmp, tmp + M);
  for(int i = 0; i < M; i++){
    J[i] = tmp[i].first;
    V[i] = tmp[i].second;
  }
}

void solve(){
  if(K == 0){
    cout << 0 << '\n';
    return;
  }
  if(K == 1){
    cout << 1 % P << '\n';
    return;
  }
  if(N > 1){
    ll cur = 1, prev = S[1];
    matrix m = {S[1], S[0], 1, 0};
    for(int i = 0; i < M; i++){
      if(J[i] >= K) break;
      if(cur < J[i] - 1){
        matrix tmp = {S[(cur + 1) % N], prev, 1, 0};
        m = m * tmp;
        prev = S[(cur + 1) % N];
        cur += 1;
      }
      if(cur < J[i] - 1){
        m = m * get(cur, J[i] - 2);
        prev = S[(J[i] - 1) % N];
        cur = J[i] - 1;
      }
      matrix tmp = {V[i], prev, 1, 0};
      m = m * tmp;
      prev = V[i];
      cur += 1;
    }
    if(cur < K - 1){
      matrix tmp = {S[(cur + 1) % N], prev, 1, 0};
      m = m * tmp;
      cur += 1;
    }
    if(cur < K - 1){
      m = m * get(cur, K - 2);
      cur = K - 1;
    }
    cout << m.a % P << '\n';
  } else {
    ll cur = 1, prev = S[0];
    int start = 0;
    matrix m = {S[0], S[0], 1, 0};
    if(J[0] == 1){
      start = 1;
      m = {V[0], S[0], 1, 0};
      prev = V[0];
    }
    for(int i = start; i < M; i++){
      if(J[i] >= K) break;
      if(cur < J[i] - 1){
        matrix tmp = {S[(cur + 1) % N], prev, 1, 0};
        m = m * tmp;
        prev = S[(cur + 1) % N];
        cur += 1;
      }
      if(cur < J[i] - 1){
        m = m * get(cur, J[i] - 2);
        prev = S[(J[i] - 1) % N];
        cur = J[i] - 1;
      }
      matrix tmp = {V[i], prev, 1, 0};
      m = m * tmp;
      prev = V[i];
      cur += 1;
    }
    if(cur < K - 1){
      matrix tmp = {S[(cur + 1) % N], prev, 1, 0};
      m = m * tmp;
      cur += 1;
    }
    if(cur < K - 1){
      m = m * get(cur, K - 2);
      cur = K - 1;
    }
    cout << m.a % P << '\n';
  }
}

int main(){
  read();
  build();
  reindex();
  solve();
}