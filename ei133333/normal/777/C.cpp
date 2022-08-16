#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int n, m, q;

  cin >> n >> m;
  vector< vector< int > > a(n, vector< int >(m));
  vector< int > range(n, -INF);
  vector< int > bigs(n, -INF);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < m; i++) {
    int begin = 0, pv = -1;
    for(int j = 0; j < n; j++) {
      if(pv > a[j][i]) {
        range[begin] = max(range[begin], j - 1);
        begin = j;
      }
      pv = a[j][i];
    }
    range[begin] = max(range[begin], n - 1);
  }

  int big = 0;
  for(int i = 0; i < n; i++) {
    big = max(big, range[i]);
    bigs[i] = big;
  }

  cin >> q;
  for(int i = 0; i < q; i++) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    if(bigs[c] >= d) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}