#include<bits/stdc++.h>

using namespace std;

int N;
vector< int > g[100000];

double rec(int idx, int par = -1)
{
  double ret = 0.0;
  int child = 0;
  for(auto &to : g[idx]) {
    if(par != to) {
      ++child;
    }
  }
  for(auto &to : g[idx]) {
    if(par != to) {
      ret += (rec(to, idx) + 1.0) / child;
    }
  }
  return(ret);
}

int main()
{
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << fixed << setprecision(10) << rec(0) << endl;
}