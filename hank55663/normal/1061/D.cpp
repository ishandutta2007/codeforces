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
LL mod=1e9+7;
int main(){
    LL n,x,y;
    scanf("%lld %lld %lld",&n,&x,&y);
    LL ans=0;
    pii p[100005];
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
    }
    sort(p,p+n);
    priority_queue<int,vector<int>,greater<int> > pq;
    priority_queue<int> ok;
    for(int i=0;i<n;i++){
        while(!pq.empty()&&pq.top()<p[i].x){
            ok.push(pq.top());
            pq.pop();
        }
        if(ok.empty()){
            pq.push(p[i].y);
            ans+=x+(p[i].y-p[i].x)*y%mod;
            ans%=mod;
        }
        else{
            int xx=ok.top();
            ok.pop();
            if((p[i].x-xx)*y<x){
                ans+=(p[i].y-xx)*y%mod;
                ans%=mod;
            }
            else{
                ans+=x+(p[i].y-p[i].x)*y%mod;
                ans%=mod;
            }
            pq.push(p[i].y);
        }
      //  printf("%d\n",ans);
    }
    printf("%lld\n",ans);
}