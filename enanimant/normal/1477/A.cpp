/*
 * author:  ADMathNoob
 * created: 01/28/21 09:36:58
 * problem: https://codeforces.com/contest/1477/problem/A
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1477A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1477A.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] -= k;
    }
    for (int i = 0; i < n; i++) {
      cerr << a[i] << ' ';
    }
    cerr << '\n';
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = (int) a.size();
    if (n == 1) {
      cout << (a[0] == 0 ? "yes" : "no") << '\n';
      continue;
    }
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
      d[i] = a[i + 1] - a[i];
    }
    long long g = accumulate(d.begin(), d.end(), 0LL, gcd);
    cout << (a[0] % g == 0 ? "yes" : "no") << '\n';
  }


  return 0;
}