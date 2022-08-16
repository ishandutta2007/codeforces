#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, K[100000];
vector< int > g[100000];

int64 rec(int idx, int par = -1)
{
  vector< int64 > child;
  for(int to : g[idx]) {
    if(par != to) {
      --K[to];
      child.push_back(rec(to, idx) + 2);
    }
  }
  sort(child.begin(), child.end());
  int64 ret = 0;
  for(int i = child.size() - 1; i >= 0 && K[idx]; --i) {
    ret += child[i];
    --K[idx];
  }
  for(auto to : g[idx]) {
    if(par != to) {
      int64 v = min(K[idx], K[to]);
      K[idx] -= v;
      ret += 2 * v;
    }
  }
  return(ret);
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> K[i];
  }
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int S;
  cin >> S;
  cout << rec(--S) << endl;
}