#include <bits/stdc++.h>

using namespace std;

int N;
vector< int > g[100000];

double rec(int idx, int depth, int par)
{
  double ret = 1.0 / depth;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    ret += rec(to, depth + 1, idx);
  }
  return (ret);
}

int main()
{
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << fixed << setprecision(10) << rec(0, 1, -1) << endl;
}