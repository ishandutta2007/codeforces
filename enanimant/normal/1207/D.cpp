// August 22, 2019
// https://codeforces.com/contest/1207/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 998244353;
const int N = 300005;


int fact[N];

int n;
pair<int, int> s[N];

int f(const vector<int> &v) {
  int n = (int) v.size();
  int last = 0;
  int res = 1;
  for (int i = 0; i <= n; i++) {
    if (i == n || v[i] != v[last]) {
      int cnt = i - last;
      res = 1LL * res * fact[cnt] % MOD;
      last = i;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second;
  }
  // total perms
  int ans = fact[n];
  // total with first sorted
  sort(s, s + n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = s[i].first;
  }
  ans -= f(v);
  ans = (ans % MOD + MOD) % MOD;
  // total with both sorted
  int both = 1;
  int last = 0;
  for (int i = 0; i <= n; i++) {
    if (i == n || s[i].first != s[last].first) {
      if (i != n && s[i - 1].second > s[i].second) {
        both = 0;
        break;
      }
      vector<int> v;
      for (int j = last; j < i; j++) {
        v.push_back(s[j].second);
      }
      both = 1LL * both * f(v) % MOD;
      last = i;
    }
  }
  ans += both;
  ans %= MOD;
  // total with second sorted
  sort(s, s + n, [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  });
  for (int i = 0; i < n; i++) {
    v[i] = s[i].second;
  }
  ans -= f(v);
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << '\n';


  return 0;
}