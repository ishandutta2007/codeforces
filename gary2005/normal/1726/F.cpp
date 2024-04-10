/**
 *    author:  gary
 *    created: 06.09.2022 22:26:33
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=3e5+20;
int n,T,g[MAXN],c[MAXN],d[MAXN],magic,pre[MAXN],d2[MAXN],id[MAXN];
LL presum[MAXN],dp[MAXN];
vector<mp> seg[MAXN];
vector<int> segp[MAXN];
void chk(vector<mp> &v){
    sort(ALL(v));
    vector<mp> newv;
    for(auto it:v){
        if(newv.empty()||newv.back().second<it.first-1) newv.push_back(it);
        else check_max(newv.back().second,it.second);
    }
    v.swap(newv);
}
bool orz(vector<int> &v,int t){
    return (upper_bound(ALL(v),t)-v.begin())&1;
}
mp query(int from,int t){
    if(from>n) return II(n+1,0);
    if(from%magic==1&&!orz(segp[id[from]],t)){
        return query(from+magic,((t+pre[min(n,from+magic-1)]-pre[from-1])%T+T)%T);
    }
    else{
        int Z=t+c[from];
        if(Z>=T) Z-=T;
        if(Z<g[from]){
            int Y=t+d2[from];
            if(Y>=T) Y-=T;
            return query(from+1,Y);
        }
        else{
            return II(from,T-Z);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>T;
    rb(i,1,n) cin>>g[i]>>c[i];
    LL ans=1e18;
    rb(i,1,n-1) cin>>d[i];
    rb(i,1,n) pre[i]=pre[i-1]+d[i],d2[i]=d[i]%T,pre[i]%=T,presum[i]=presum[i-1]+d[i];
    magic=ceil(sqrt(n*max(1.0,log2(n))));
    check_max(magic,2);
    rb(i,1,n){
        if(i%magic==1) id[i]=i;
        else id[i]=id[i-1];
        int l=g[i];
        int r=T-1;
        l-=c[i],r-=c[i];
        l%=T,r%=T;
        if(l<0) l+=T;
        if(r<0) r+=T;
        l-=(pre[i-1]-pre[id[i]-1]+T)%T;
        r-=(pre[i-1]-pre[id[i]-1]+T)%T;
        if(l<0) l+=T;
        if(r<0) r+=T;
        if(l<=r) seg[id[i]].emplace_back(l,r);
        else seg[id[i]].emplace_back(l,T-1),seg[id[i]].emplace_back(0,r);
    }
    rb(i,1,n) {chk(seg[i]);for(auto it:seg[i]) segp[i].push_back(it.first),segp[i].push_back(it.second+1);}
    rl(i,n,1){
        int f=0;
        f-=c[i];
        f%=T;
        if(f<0) f+=T;
        auto temp=query(i,f);
        dp[i]=presum[temp.first-1]-presum[i-1]+temp.second+dp[temp.first];
    }
    vector<int> use;
    rb(i,1,n){
        int l,r;
        l=0,r=g[i]-1;
        l-=c[i],r-=c[i];
        l%=T,r%=T;
        l-=pre[i-1],r-=pre[i-1];
        l%=T,r%=T;
        if(l<0) l+=T;
        if(r<0) r+=T;
        // use.push_back(l);
        l--;
        if(l<0) l+=T;
        // use.push_back(l);
        use.push_back(r);
        r++;
        r%=T;
        // use.push_back(r);
    }
    sort(ALL(use));
    use.erase(unique(ALL(use)),use.end());
    for(auto f:use){
        auto temp=query(1,f);
        check_min(ans,presum[temp.first-1]+temp.second+dp[temp.first]);
    }
    cout<<ans<<endl;
    return 0;
}