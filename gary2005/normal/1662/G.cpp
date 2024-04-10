/**
 *    author:  gary
 *    created: 24.04.2022 20:31:28
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e6+10;
int n;
vector<int> g[MAXN];
LL sumsize[MAXN];
int siz[MAXN];
void dfs1(int now,int pre){
    siz[now]=1;
    for(auto it:g[now]) if(it!=pre) dfs1(it,now),siz[now]+=siz[it],sumsize[now]+=sumsize[it];
    sumsize[now]+=siz[now];
}
LL ans=0;
void calc(int now){
    bool ok=0;
    for(auto it:g[now]) if(siz[it]>(n+1)/2) ok=1;
    LL tmp=0;
    if(ok){
        LL s1,s2;
        s1=0,s2=0;
        for(auto it:g[now]) if(siz[it]>(n+1)/2) s1+=siz[it];
        else s2+=siz[it];
        tmp=s1*s2;
    }
    else{
        bitset<1000000> dp;
        dp.set(0);
        map<int,int> obj;
        for(auto it:g[now]) obj[siz[it]]++;
        for(auto ite=obj.begin();ite!=obj.end();ite++){
            while(ite->second>=3){
                obj[ite->first*2]++;
                ite->second-=2;
            }
            rb(i,1,ite->second){
                dp|=dp<<ite->first;
            }
        }
        rep(i,1e6) if(dp[i]) check_max(tmp,1ll*i*(n-1-i));
    }
    check_max(ans,tmp+sumsize[now]);
}
void dfs2(int now,int pre){
    calc(now);
    int x=siz[now];
    LL y=sumsize[now];
    for(auto it:g[now]) if(it!=pre){
        siz[now]=x;
        sumsize[now]=y;
        sumsize[now]-=siz[now];
        siz[now]-=siz[it];
        sumsize[now]+=siz[now];
        sumsize[now]-=sumsize[it];
        sumsize[it]-=siz[it];
        siz[it]+=siz[now];
        sumsize[it]+=siz[it];
        sumsize[it]+=sumsize[now];
        dfs2(it,now);
    }
}
int main(){
    scanf("%d",&n);
    rb(i,2,n){
        int pi;
        scanf("%d",&pi);
        g[i].PB(pi);
        g[pi].PB(i);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans<<endl;
    return 0;
}