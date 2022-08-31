#include <bits/stdc++.h>

using namespace std;

vector< int > g[1000000];
bool b[1000000];
vector< int > order;
int rev[1000000];


void dfs(int idx)
{
  if(b[idx]++) return;
  for(int to : g[idx]) dfs(to);
  order.push_back(idx);
}

int main()
{
  int N, M;

  cin >> N >> M;

  int latte = M;

  for(int i = 0; i < N; i++) {
    vector< pair< int, int > > v;
    for(int j = 0; j < M; j++) {
      int s;
      cin >> s;
      if(~s) v.emplace_back(s, j);
    }
    sort(begin(v), end(v));

    int last = 0;
    for(int j = 1; j < v.size(); j++) {
      if(v[last].first != v[j].first) {
        int nxt = j;
        while(nxt < v.size() && v[nxt].first == v[j].first) ++nxt;
        for(int k = last; k < j; k++) g[v[k].second].push_back(latte);
        for(int k = j; k < nxt; k++) g[latte].push_back(v[k].second);
        last = j;
        ++latte;
      }
    }
  }

  for(int i = 0; i < latte; i++) dfs(i);
  reverse(begin(order), end(order));
  for(int i = 0; i < latte; i++) rev[order[i]] = i;
  bool malta = false;
  for(int i = 0; i < latte; i++) {
    for(int to : g[i]) if(rev[i] >= rev[to]) malta = true;
  }
  if(malta) {
    cout << -1 << endl;
  } else {
    for(int i = 0; i < latte; i++) {
      if(order[i] < M) cout << order[i] + 1 << " ";
    }
    cout << endl;
  }
}