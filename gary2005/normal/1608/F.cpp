/**
 *    author:  gary
 *    created: 20.05.2022 15:32:30
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
const int MAXN=2002;
const int MOD=998244353;
int n,k,b[MAXN],comb[MAXN][MAXN],fact[MAXN];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
struct dp{
    int f[101][MAXN];
    dp(){memset(f,0,sizeof(f));}
};
int f[MAXN][MAXN];
dp Trans(int A,int B,dp from){
    if(A-k>B+k){
        cout<<0<<endl;
        exit(0);
    }
    dp rest;
    int L=max(0,A-k),R=min(n,B+k);
    rb(i,L,R) memset(f[i],0,sizeof(f[i]));
    rb(i,-k,k){
        rb(j,0,n) if(from.f[i+k][j]){
            int reali=i+A;
            if(abs(reali-B)<=k) add(rest.f[reali-B+k][j+1],from.f[i+k][j]),add(rest.f[reali-B+k][j],1ll*j*from.f[i+k][j]%MOD),add(rest.f[reali-B+k][j],1ll*reali*from.f[i+k][j]%MOD);
            reali=i+A+1;
            if(reali>=L&&reali<=R)
            add(f[reali][j],from.f[i+k][j]);
        }
    }
    rb(i,L,R-1){
        rb(j,1,n) add(f[i+1][j-1],1ll*j*f[i][j]%MOD);
    }
    rb(i,-k,k){
        int reali=i+B;
        if(reali<=R&&reali>=L) rb(j,0,n) {
            add(rest.f[i+k][j],f[reali][j]);
        }
    }
    return rest;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rb(i,1,n) cin>>b[i];
    rb(i,0,n) comb[i][0]=1;
    rb(i,1,n) rb(j,1,n) comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
    b[0]=0;
    dp now;
    now.f[k][0]=1;
    rb(i,1,n){
        now=Trans(b[i-1],b[i],now);
    }
    fact[0]=1;
    rb(i,1,n) fact[i]=1ll*fact[i-1]*i%MOD;
    int ans=0;
    rb(i,-k,k) rb(j,0,n) if(now.f[i+k][j]){
        int reali=i+b[n];
        add(ans,1ll*now.f[i+k][j]*comb[n-reali][j]%MOD*fact[j]%MOD);
    }
    cout<<ans<<endl;
    return 0;
}