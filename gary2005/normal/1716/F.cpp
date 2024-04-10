/**
 *    author:  gary
 *    created: 04.08.2022 22:25:27
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
const int MAXN=2e3+20;
const int MOD=998244353;
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
int s[MAXN][MAXN],iv[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    s[0][0]=1;
    rb(i,1,2000) rb(j,1,i){
        s[i][j]=1ll*s[i-1][j]*j%MOD+s[i-1][j-1];
        s[i][j]%=MOD;
    }
    rb(i,1,2000) iv[i]=inv(i);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int ans=0;
        int z=quick(m,n);
        int ivm=inv(m);
        int b=(m+1)/2;
        rb(i,1,k){
            z=1ll*(n-i+1)*z%MOD;
            z=1ll*iv[i]*z%MOD;
            z=1ll*z*b%MOD;
            z=1ll*z*ivm%MOD;
            z=1ll*z*i%MOD;
            ans+=1ll*z*s[k][i]%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}