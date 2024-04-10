// May 12, 2020
// https://codeforces.com/contest/1349/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAX = 200001;

long long lcm(int a, int b) {
  return 1LL * a * b / __gcd(a, b);
}

long long power(int b, int e) {
  long long res = 1;
  for (int i = 0; i < e; i++) {
    res *= b;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  vector<int> least(MAX, -1);
  vector<int> primes;
  int cnt = 0;
  for (int i = 2; i < MAX; i++) {
    if (least[i] != -1) {
      continue;
    }
    primes.push_back(i);
    least[i] = cnt;
    for (long long j = 1LL * i * i; j < MAX; j += i) {
      if (least[j] == -1) {
        least[j] = cnt;
      }
    }
    cnt++;
  }
  
  int n;
  cin >> n;
  vector<vector<int>> exps(cnt);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] > 1) {
      int id = least[a[i]];
      int e = 0;
      while (least[a[i]] == id) {
        a[i] /= primes[id];
        e++;
      }
      exps[id].push_back(e);
    }
  }
  long long ans = 1;
  for (int i = 0; i < cnt; i++) {
    if ((int) exps[i].size() < n - 1) {
      continue;
    }
    if ((int) exps[i].size() == n - 1) {
      exps[i].push_back(0);
    }
    sort(exps[i].begin(), exps[i].end());
    ans *= power(primes[i], exps[i][1]);
  }
  cout << ans << '\n';
  
  
  return 0;
}