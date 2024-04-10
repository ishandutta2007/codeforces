#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, m, k, dst[N];
vector< pair<int,int> > v[N], bk[N];
void bfs(int now){
  dst[now]=1;
  queue<int> Q;
  Q.push(now);
  while(Q.size()){
    int tn=Q.front(); Q.pop();
    for(auto e: v[tn]){
      if(dst[e.first]) continue;
      dst[e.first]=dst[tn]+1;
      Q.push(e.first);
    }
  }
}
vector< vector<int> > ans;
vector<int> cur;
void go(int now){
  if((int)ans.size()>=k) return;
  if(now > n){
    ans.push_back(cur);
    return;
  }
  for(auto e: bk[now]){
    cur[e.second]=1;
    go(now+1);
    if((int)ans.size()>=k) return;
    cur[e.second]=0;
  }
}
int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<m; i++){
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    v[ai].push_back({bi, i});
    v[bi].push_back({ai, i});
  }
  bfs(1);
  for(int i=1; i<=n; i++)
    for(auto e: v[i])
      if(dst[e.first]+1==dst[i])
        bk[i].push_back(e);
  cur.resize(m);
  for(int i=0; i<m; i++) cur[i]=0;
  go(2);
  printf("%d\n", (int)ans.size());
  for(auto i: ans){
    for(auto j: i) printf("%d", j);
    puts("");
  }
}