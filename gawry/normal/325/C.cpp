#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int m,n;
const int MAX=110000;
const int LOTS=314000000;
const int INF=1000000000;
int smallest[MAX],largest[MAX];
vector< pair<vi,pair<int,int64> > > t[MAX];
vector< pair<int,int> > where[MAX];
vi s[MAX],s2[MAX];
bool b[MAX];
vi q;
void dfs(int x){
  b[x]=true;
  FOR(i,s[x].size())if(!b[s[x][i]])dfs(s[x][i]);
  q.push_back(x);
}
bool edge;
vi cur;
void dfs2(int x){
  b[x]=true;
  cur.push_back(x);
  FOR(i,s2[x].size()){
    edge|=!b[s2[x][i]]||s2[x][i]==x;
    if(!b[s2[x][i]])dfs2(s2[x][i]);
  }
}
priority_queue< pair<int64,pair<int,int> > > pq;
main(){
  scanf("%d %d",&m,&n);
  for(int i=1;i<=n;i++)smallest[i]=INF;
  while(m--){
    int x,L;
    scanf("%d %d",&x,&L);
    t[x].push_back(make_pair(vi(),make_pair(0,0)));
    while(L--){
      int y;
      scanf("%d",&y);
      t[x].back().first.push_back(y);
      if(y!=-1){
        ++t[x].back().second.first;
        where[y].push_back(make_pair(x,t[x].size()-1));
      }else{
        ++t[x].back().second.second;
      }
    }
    if(!t[x].back().second.first)pq.push(make_pair(-t[x].back().second.second,make_pair(x,t[x].size()-1)));
  }
  while(!pq.empty()){
    pair<int,int> what=pq.top().second;pq.pop();
    int cost=min((int64)LOTS,t[what.first][what.second].second.second);
    int previous=smallest[what.first];
    if(cost>=smallest[what.first])continue;
    smallest[what.first]=cost;
    assert(previous==INF);
    FOR(i,where[what.first].size()){
      pair<int,int> other=where[what.first][i];
      --t[other.first][other.second].second.first;
      t[other.first][other.second].second.second+=cost;
      if(!t[other.first][other.second].second.first){
        assert(t[other.first][other.second].second.second>cost);
        pq.push(make_pair(-t[other.first][other.second].second.second,other));
      }
    }
  }
  for(int i=1;i<=n;i++)if(smallest[i]<INF)FOR(j,t[i].size()){
    bool ok=true;
    FOR(k,t[i][j].first.size())ok&=t[i][j].first[k]==-1||smallest[t[i][j].first[k]]<INF;
    if(ok)FOR(k,t[i][j].first.size())if(t[i][j].first[k]>-1){
      //printf("%d -> %d\n",i,t[i][j].first[k]);
      s[i].push_back(t[i][j].first[k]);
      s2[t[i][j].first[k]].push_back(i);
    }
  }
  memset(b,0,sizeof(b));
  for(int i=1;i<=n;i++)if(smallest[i]<INF)if(!b[i])dfs(i);
  memset(b,0,sizeof(b));
  memset(largest,-1,sizeof(largest));
  for(int i=q.size()-1;i>=0;i--)if(!b[q[i]]){
    edge=false;
    cur.clear();
    dfs2(q[i]);
    if(edge)FOR(j,cur.size())largest[cur[j]]=INF;
  }
  FOR(i,q.size())if(largest[q[i]]==-1){
    int x=q[i];
    largest[x]=0;
  //  printf("x=%d\n",x);
    FOR(j,t[x].size()){
      bool ok=true;
      FOR(k,t[x][j].first.size())ok&=t[x][j].first[k]==-1||smallest[t[x][j].first[k]]<INF;
      if(!ok)continue;
      int sum=0;
      FOR(k,t[x][j].first.size())if(t[x][j].first[k]>-1){
        int add=largest[t[x][j].first[k]];
        if(add==INF)sum=INF;
        else if(sum<INF)sum=min(sum+add,LOTS);
//        printf("-> %d %d =%d\n",t[x][j].first[k],add,sum);
      }else if(sum<INF)sum=min(sum+1,LOTS);
//      printf("%d ? %d\n",j,sum);
      largest[x]=max(largest[x],sum);
    }
//    printf("x=%d largest=%d\n",x,largest[x]);
  }
  for(int i=1;i<=n;i++)if(smallest[i]==INF)puts("-1 -1");else{
    printf("%d %d\n",smallest[i],largest[i]==INF?-2:largest[i]);
  }
}