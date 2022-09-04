/*#include<stdio.h>
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
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
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
#define plus Plus
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
int d[300005];
vector<int> v[300005];
LL S[1<<20];
void add(int x,int k){
    for(int i=x;i<(1<<20);i+=i&-i){
        S[i]+=k;
    }
}
LL query(int x){
    LL res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void dfs(int x,int f,int dis){
    d[x]=dis;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,dis+1);
        }
    }
}
vector<pii> plus[300005];
LL ans[300005];
void dfs2(int x,int f,LL sum){
  //  printf("%d\n",x);
    for(auto it:plus[x]){
        add(it.x+1,it.y);
        sum+=it.y;
    }
    ans[x]=sum-query(d[x]);
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,sum);
        }
    }
    for(auto it:plus[x]){
        add(it.x+1,-it.y);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,1);
    int m;
    scanf("%d",&m);
    while(m--){
        int a,dd,x;
        scanf("%d %d %d",&a,&dd,&x);
        plus[a].pb(mp(dd+d[a],x));
    }
    dfs2(1,0,0);
    for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
    printf("\n");
}