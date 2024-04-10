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
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
vector<pii> v[300005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    map<pii,int> mm;
    for(int i=0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
        mm[mp(x,y)]=i+1;
        mm[mp(y,x)]=i+1;
    }
    LL d[300005];
    fill(d,d+n+1,1e18);
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push(mp(0,1));
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        if(d[p.y]!=1e18)
        continue;
        d[p.y]=p.x;
        for(auto it:v[p.y]){
            if(d[it.x]==1e18){
                pq.push(mp(it.y+p.x,it.x));
            }
        }
    }
    vector<pll> node;
    for(int i=1;i<=n;i++){
        node.pb(mp(d[i],i));
    }
    sort(node.begin(),node.end());
    vector<int> ans;
    for(int i=1;i<=k&&i<node.size();i++){
        for(auto it:v[node[i].y]){
            if(d[it.x]+it.y==node[i].x){
                ans.pb(mm[mp(it.x,node[i].y)]);
                break;
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d ",it);
    printf("\n");
}