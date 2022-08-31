#include <bits/stdc++.h>

using namespace std;


int N, M;
vector< int > beet[300001];
vector< int > g[300001];
int color[300001];
int used[300001];

void dfs(int idx, int par = -1)
{
  vector< bool > used(beet[idx].size() + 1, 0);
  for(auto &c : beet[idx]) {
    if(~color[c]) used[min((int) beet[idx].size(), color[c])] = idx;
  }
  int tail = 0;
  for(auto &c : beet[idx]) {
    while(used[tail]) ++tail;
    if(!~color[c]) color[c] = tail++;
  }
  for(auto &to : g[idx]) {
    if(to != par) dfs(to, idx);
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    int S;
    scanf("%d", &S);
    while(S--) {
      int t;
      scanf("%d", &t);
      beet[i].push_back(t);
    }
  }

  for(int i = 1; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  memset(used, -1, sizeof(used));
  memset(color, -1, sizeof(color));
  dfs(0);

  int res = 1;
  for(int i = 1; i <= M; i++) res = max(res, color[i] + 1);
  cout << res << endl;
  for(int i = 1; i <= M; i++) cout << max(1, color[i] + 1) << " ";
  cout << endl;
}