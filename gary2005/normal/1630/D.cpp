/**
 *    author:  gary
 *    created: 27.01.2022 22:29:55
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
const int MAXN=1e6+1;
int n,m,a[MAXN];
vector<int> q[MAXN],t[MAXN];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void solve(){
    cin>>n>>m;
    rb(i,1,n) cin>>a[i];
    int g=0;
    rb(i,1,m){
        int bi;
        cin>>bi;
        g=gcd(g,bi);
    }
    rep(i,g) q[i].clear();
    LL ans=0;
    rb(i,1,n) ans+=a[i];
    rb(i,1,n) q[i%g].PB(a[i]);
    rep(i,g) sort(ALL(q[i]));
    LL tmp=0;
    LL res=-1e18;
    rep(f,2){
        tmp=ans;
        rep(i,g) t[i]=q[i];
        rep(i,g){
            reverse(ALL(t[i]));
            if(f){
                tmp-=t[i].back()*2;
                t[i].POB();
            }
            while(t[i].size()>=2&&-2ll*(t[i][t[i].size()-1]+t[i][t[i].size()-2])>0){
                tmp-=2ll*(t[i][t[i].size()-1]+t[i][t[i].size()-2]);
                t[i].POB();
                t[i].POB();
            }
        }
        check_max(res,tmp);
    }
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}