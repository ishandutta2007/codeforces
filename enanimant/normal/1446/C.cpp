// November 13, 2020
// https://codeforces.com/contest/1446/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446C.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int LOG = 32;

int Solve(vector<unsigned> a) {
  if ((int) a.size() <= 1) {
    return (int) a.size();
  }
  vector<vector<unsigned>> group(LOG);
  for (unsigned x : a) {
    int g = 31 - __builtin_clz(x);
    group[g].push_back(x ^ (1 << g));
  }
  int sum_less = 0;
  int ans = 0;
  for (int i = 0; i < LOG; i++) {
    int res = 0;
    if (sum_less > 0) {
      res += 1;
    }
    res += Solve(group[i]);
    for (int j = i + 1; j < LOG; j++) {
      if (!group[j].empty()) {
        res += 1;
      }
    }
    ans = max(ans, res);
    sum_less += (int) group[i].size();
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<unsigned> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] * 2 + 1;
  }
  // sort(a.begin(), a.end());
  cout << n - Solve(a) << '\n';


  return 0;
}