#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;


int N;
pair< int, int > A[100];
int bit[60];
int uku[100];

vector< bool > get_prime(int n) {
  vector< bool > prime(n + 1, true);

  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;

  for(int i = 2; i * i <= n; i++) {
    if(prime[i]) {
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }

  return (prime);
}

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}


map< int, int > come[60][100];

int dfs(int k, int b, int idx) {
  if(idx == -1) return 0;
  if(k == 1) return uku[idx];
  if(come[k][idx].count(b)) return come[k][idx][b];
  int ret = INF;
  if(b & bit[k]) {
    ret = min(ret, dfs(k - 1, b, idx));
  } else {
    ret = min(ret, dfs(k - 1, b, idx));
    ret = min(ret, dfs(k - 1, b | bit[k], idx - 1) + abs(k - A[idx].first));
  }
  return come[k][idx][b] = ret;
}

int dump[100];

void dfs2(int k, int b, int idx) {

  if(idx == -1) return;
  if(k == 1) {
    for(int p = 0; p <= idx; p++) dump[p] = 1;
    return;
  }
  int ret = come[k][idx][b];
  if(b & bit[k]) {
    dfs2(k - 1, b, idx);
  } else {
    if(ret == dfs(k - 1, b, idx)) {
      dfs2(k - 1, b, idx);
    } else {
      dump[idx] = k;
      dfs2(k - 1, b | bit[k], idx - 1);
    }
  }
}


int main() {
  auto primes = get_prime(60);
  int to[60] = {}, ptr = 0;
  for(int i = 1; i < primes.size(); i++) {
    if(primes[i]) to[i] = ptr++;
  }
  for(int i = 2; i < 60; i++) {
    auto pp = prime_factor(i);
    for(auto p : pp) bit[i] |= 1 << to[p.first];
  }

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A, A + N);
  for(int i = 0; i < N; i++) {
    uku[i] = abs(A[i].first - 1);
    if(i > 0) uku[i] += uku[i - 1];
  }
  dfs(59, 0, N - 1);
  dfs2(59, 0, N - 1);
  vector< int > set(N);
  for(int i = 0; i < N; i++) {
    set[A[i].second] = dump[i];
  }
  for(int i = 0; i < N; i++) {
    cout << set[i] << " ";
  }
  cout << endl;
}