#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 4e5+5;
const int inf = 1e18;

map<int, int> m;
vector<ii> v;
int qnt[ms];
vector<vector<int>> mat;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    m[u]++;
  }
  for(auto &e : m) {
    v.emplace_back(e.second, e.first);
    qnt[e.second]++;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int p = n;
  pair<int, int> cur = {0, 0};
  while(n > 0) {
    if(p * p <= n) cur = max(cur, make_pair(p * (n/p), p));
    n -= qnt[p];
    qnt[p-1] += qnt[p];
    p--;
  }
  n = cur.first;
  p = cur.second;
  int q = n / p;
  cout << p*q << '\n';
  cout << p << ' ' << q << '\n';
  mat.resize(p);
  for(int i= 0 ; i < p; i++) {
    mat[i].resize(q);
  }
  int curI = 0, curJ = 0;
  for(auto e : v) {
    int u = e.second;
    int qnt = min(e.first, p);
    for(int i = 0; i < qnt && n > 0; i++) {
      n--;
      mat[curJ][(curI+curJ)%q] = u;
      curJ++;
      if(curJ == p) {
        curJ = 0;
        curI++;
      }
    }
  }
  for(int i = 0; i < p; i++) {
    for(int j = 0; j < q; j++) {
      cout << mat[i][j] << ' ' ;
    }
    cout << '\n';
  }
}