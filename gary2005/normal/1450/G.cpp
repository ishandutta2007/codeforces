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
int n,a,b;
string s,is;
mp seg[1<<20];
int app[300],tot[1<<20];
bool ok[1<<20],w[1<<20],dp[1<<20];
struct cmp{
    bool operator () (const char &A,const char &B) const{
        return app[A]<app[B];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    cin>>s;
    rep(i,n) app[s[i]]=i;
    map<char,int,cmp> id;
    for(auto it:s) id[it]=1;
    int cnt=0;
    for(auto &it:id) it.second=cnt++,is.push_back(it.first);
    rep(i,cnt) seg[1<<i]=II(INF,-INF);
    rep(i,n){
        s[i]=id[s[i]];   
        tot[1<<s[i]]++;
        check_min(seg[1<<s[i]].first,i);
        check_max(seg[1<<s[i]].second,i);
    }
    rep(i,1<<cnt){
        if(__builtin_popcount(i)>=2)
        rep(j,cnt){
            if((i>>j)&1){
                tot[i]=tot[i^(1<<j)]+tot[1<<j];
                seg[i]=seg[i^(1<<j)];
                check_min(seg[i].first,seg[1<<j].first);
                check_max(seg[i].second,seg[1<<j].second);
                break;
            }
        }
    }
    rep(mask,1<<cnt) if(mask){
        LL A,B;
        A=tot[mask];
        B=seg[mask].second-seg[mask].first+1;
        if(A*b>=a*B){
            ok[mask]=1;
        }
    }
    w[0]=dp[0]=ok[0]=1;
    rep(i,cnt) dp[1<<i]=1,w[1<<i]=ok[1<<i];
    rep(mask,1<<cnt) if(__builtin_popcount(mask)>=2){
        rep(j,cnt) if((mask>>j)&1) if(w[mask^(1<<j)]){
            dp[mask]=1;
        }
        rep(j,cnt+1) w[mask]|=w[(mask>>j)<<j]&dp[mask&((1<<j)-1)]&ok[mask&((1<<j)-1)];
    }
    vector<char> res;
    rep(i,cnt) if(w[((1<<cnt)-1)^(1<<i)]) res.push_back(is[i]);
    sort(ALL(res));
    cout<<res.size()<<' ';
    for(auto it:res) cout<<it<<' ';
    cout<<endl;
    return 0;
}