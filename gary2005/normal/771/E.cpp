/**
 *    author:  gary
 *    created: 10.11.2021 16:43:45
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
const int MAXN=3e5+3;
int n,a[2][MAXN];
map<mp,int> dp;
int nx[3][MAXN];
int solve(int i,int j){
    if(dp.find(II(i,j))!=dp.end()) return dp[II(i,j)];
    int & val=dp[II(i,j)];
    val=0;
    if(i>=j){
        if(nx[1][j]<=n)
            check_max(val,solve(i,nx[1][j]+1)+1);
        if(i>j)
        check_max(val,solve(i,i));
    }
    if(i<=j){
        if(nx[0][i]<=n)
            check_max(val,solve(nx[0][i]+1,j)+1);
        if(j>i)
        check_max(val,solve(j,j));
    }
    if(nx[2][i]<=n&&nx[2][j]<=n){
        int mx=max(nx[2][i],nx[2][j]);
        check_max(val,solve(mx+1,mx+1)+1);
    }
    return val;
}
int main(){
    cin>>n;
    rep(i,2) rb(j,1,n) scanf("%d",&a[i][j]);
    map<LL,int> u,d,m;
    LL prea,preb,prec;
    prea=preb=prec=0;
    u[0]=d[0]=m[0]=0;
    vector<mp> seg[3];
    rb(j,1,n){
        prea+=a[0][j];
        preb+=a[1][j];
        prec+=a[0][j]+a[1][j];
        if(u.find(prea)!=u.end()) seg[0].PB(II(u[prea]+1,j));
        if(d.find(preb)!=d.end()) seg[1].PB(II(d[preb]+1,j));
        if(m.find(prec)!=m.end()) seg[2].PB(II(m[prec]+1,j));
        u[prea]=j;
        d[preb]=j;
        m[prec]=j;
    }
    memset(nx,63,sizeof(nx));
    rep(j,3)
        for(auto it:seg[j]) check_min(nx[j][it.FIR],it.SEC);
    rep(j,3)
        rl(i,n,1) check_min(nx[j][i],nx[j][i+1]);
    cout<<solve(1,1)<<endl;
    return 0;
}