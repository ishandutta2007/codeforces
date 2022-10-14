/**
 *    author:  gary
 *    created: 26.02.2022 13:04:07
**/
#include<bits/stdc++.h>
#define int long long
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
const int MAXN=2e6+10;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A-=B;
    if(A<0) A+=MOD;
}
int quick(int k1,int k2){
	int k3=1;for(;k2;k2>>=1,k1=k1*k1%MOD)if(k2&1)k3=k3*k1%MOD;return k3;
}
int R;
int dp[MAXN],pre[MAXN],ifact[MAXN],prepw[MAXN],pren[MAXN];
int S(int n){
    int res=0;
    rb(i,0,min(n,R)){
        if(pren[i]!=n){
            if(n>1+pren[i]){
                int &k3=prepw[i];
                int k2=n-pren[i];
                int k1=i;
                for(;k2;k2>>=1,k1=k1*k1%MOD)if(k2&1)k3=k3*k1%MOD;
            }
            else{
                prepw[i]=prepw[i]*i%MOD;
            }
            pren[i]=n;
        }
        res+=prepw[i]*ifact[i]%MOD*pre[min(n,R)-i]%MOD;
    }
    return res%MOD;
}
int n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>R;
    if(n==1||R==1){
        cout<<1<<endl;
        return 0;
    }
    int ifa=1;
    rb(i,1,n) ifa=ifa*i%MOD;
    rb(i,0,n) prepw[i]=1,pren[i]=0;
    ifact[n]=quick(ifa,MOD-2);
    rl(i,n-1,0) ifact[i]=(i+1)*ifact[i+1]%MOD;
    rb(i,0,n) pre[i]=(i&1? (MOD-ifact[i]):(ifact[i]));
    rb(i,1,n) add(pre[i],pre[i-1]);
    rl(i,n,1){
        dp[i]=S((n+i-1)/i);
        for(int j=i+i;j<=n;j+=i) dp[i]+=MOD-dp[j];
        if(n%i) dp[i]+=MOD-dp[n];
        dp[i]%=MOD;
    }
    cout<<dp[1]<<endl;
    return 0;
}