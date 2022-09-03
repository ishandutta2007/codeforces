#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL unsigned long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
vector<int> v[100005];
int Size[100005];
int cost[100005];
int dfs(int x){
    if(v[x].size()==0){
        return Size[x]=1;
    }
    int Max=0;
    for(auto it:v[x]){
        Size[x]+=dfs(it);
        Max=max(Max,Size[it]);
    }
  //  printf("%d %d %d\n",x,Size[x],cost[x]);
    return Size[x];
}
int main(){
    int n;
    scanf("%d",&n);
    int indegree[100005];
    MEM(indegree);
    int p[100005];
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        indegree[p[i]]++;
        v[p[i]].pb(i);
    }
    dfs(1);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            pq.push(mp(0,i));
        }
    }
    int now=1;
    for(int i=1;i<=n;i++){
        pii pp=pq.top();
        pq.pop();
        now=max(pp.x,now);
        printf("%d ",now);
        if(--indegree[p[pp.y]]==0){
            pq.push(mp(Size[p[pp.y]],p[pp.y]));
        }
    }
}