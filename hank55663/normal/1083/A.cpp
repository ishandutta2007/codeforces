/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int w[300005];
vector<pii> v[300005];
LL ans;
LL dfs(int x,int f){
  //  printf("%d\n",x);
    vector<LL> down;
    down.pb(0);
    for(auto it:v[x]){
        if(it.x!=f){
            LL value=dfs(it.x,x);
            down.pb(value-it.y);
        }
    }
    sort(down.begin(),down.end());
    reverse(down.begin(),down.end());/*
    printf("%d ",x);
    for(auto it:down)
    printf("%d ",it);
    printf("\n");*/
    if(down.size()>=2){
        ans=max(ans,down[0]+down[1]+w[x]);
    }
    else{
        ans=max(ans,down[0]+w[x]);
    }
    return down[0]+w[x];
}
int main(){
    ans=-1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }
    dfs(1,0);
    printf("%lld\n",ans);
}