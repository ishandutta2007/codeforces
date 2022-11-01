// October 4, 2020
//

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422B.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


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
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    long long ans = 0;
    for (int i = 0; i <= n - 1 - i; i++) {
      for (int j = 0; j <= m - 1 - j; j++) {
        vector<int> x(1, i), y(1, j);
        vector<int> v(1, a[i][j]);
        int ii = n - 1 - i;
        int jj = m - 1 - j;
        if (i != ii) {
          x.push_back(ii);
          y.push_back(j);
          v.push_back(a[ii][j]);
        }
        if (j != jj) {
          x.push_back(i);
          y.push_back(jj);
          v.push_back(a[i][jj]);
        }
        if (i != ii && j != jj) {
          x.push_back(ii);
          y.push_back(jj);
          v.push_back(a[ii][jj]);
        }
        int cnt = (int) v.size();
        sort(v.begin(), v.end());
        long long s = v[cnt / 2];
        for (int k = 0; k < cnt; k++) {
          ans += abs(s - a[x[k]][y[k]]);
        }
      }
    }
    cout << ans << '\n';
  }


  return 0;
}