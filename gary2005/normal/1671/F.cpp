/**
 *    author:  gary
 *    created: 22.04.2022 22:54:32
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
const int MOD=998244353;
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int dp[12][12][12][12];// i0  j  a[i]<a[i+1]k  l
int f[12][12][12][12];// i0  j  a[i]<a[i+1]k  l
int g[33][12][12][12];// i  j  a[i]<a[i+1]k  l
int h[70][12][12][12];
int s[33][12][12];
int iv[200];
int comb2[55][26];
int comb(int A,int B){
    if(A<B) return 0;
    int rest=1;
    rep(i,B) rest=1ll*rest*(A-i)%MOD;
    rb(i,1,B) rest=1ll*rest*iv[i]%MOD;
    return rest;
}
int n,k,x;
int query(int N,int K,int X){
    if(K==0) return X==0;
    int rest=0;
    rb(i,1,K) rb(j,max(1,X-i),min(i,X)) add(rest,1ll*dp[i][K][X-j][j]*comb2[n-(N-i)][j]%MOD);
    return rest;
}
void solve(){
    scanf("%d%d%d",&n,&k,&x);
    if(n<=60){
        printf("%d\n",h[n][k][x][0]);
        return ;
    }
    rb(i,0,25) comb2[min(50,n)][i]=comb(max(0,n-50),i);
    rl(i,min(50,n)-1,0) rb(j,0,25){
        if(j==0) comb2[i][j]=1;
        else comb2[i][j]=(comb2[i+1][j]+comb2[i+1][j-1])%MOD;
    }
    int ans=0;
    rb(i,0,k) rb(j,0,x) {
        add(ans,1ll*s[11][i][j]*query(n-11,k-i,x-j)%MOD);
        rb(z,12,min(30,n)) if(s[z][i][j]) add(ans,1ll*s[z][i][j]*query(n-z,k-i,x-j)%MOD);
    }
    printf("%d\n",ans);
}
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    rb(i,1,11) f[1][i][0][i]=1;
    rb(i,1,11) rb(j,1,11) rb(k,0,11) rb(l,1,11) if(f[i][j][k][l]) rb(z,1,11-j) add(f[i+1][j+z][k+(l<z)][z],f[i][j][k][l]);
    rb(i,1,11) rb(j,1,11) rb(k,0,11) rb(l,1,11) add(dp[i][j][k][1],f[i][j][k][l]);
    rb(l,1,10) rb(i,1,11) rb(j,1,11) rb(k,0,11) if(dp[i][j][k][l]){
        rb(i2,1,11-i) rb(j2,i2,11-j) rb(k2,0,11-k) rb(z,1,j2) add(dp[i+i2][j+j2][k+k2][l+1],1ll*dp[i][j][k][l]*f[i2][j2][k2][z]%MOD);
    }
    g[0][0][0][11]=1;
    rb(i,0,30) rb(j,0,11) rb(k,0,11) rb(l,0,11) if(g[i][j][k][l]) rb(z,0,11-j) if(z<=i&&(i+1<12||z>=1)) add(g[i+1][j+z][k+(l<z)][z],g[i][j][k][l]);
    rb(i,0,30) rb(j,0,11) rb(k,0,11) rb(l,0,11) add(s[i][j][k],g[i][j][k][l]);
    h[0][0][0][11]=1;
    rb(i,0,65) rb(j,0,11) rb(k,0,11) rb(l,0,11) if(h[i][j][k][l]) rb(z,0,11-j) if(z<=i) add(h[i+1][j+z][k+(l<z)][z],h[i][j][k][l]);
    rb(i,0,65) rb(j,0,11) rb(k,0,11) rb(l,1,11) add(h[i][j][k][0],h[i][j][k][l]);
    rep(i,200) iv[i]=quick(i,MOD-2);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        solve();
    }
    return 0;
}