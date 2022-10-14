/**
 *    author:  gary
 *    created: 25.06.2022 22:27:27
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
const int MOD=1e9+7;
    const int MAXN=500000;
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        // cout<<fact[MAXN]<<endl;
        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
int a[200000+20];
int main(){
    genmath();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    genmath();
    rb(i,0,n) cin>>a[i];
    int ans=0;
    rb(i,0,n){
        add(ans,(comb(i+a[i],i+1))%MOD);
    }
    cout<<ans<<endl;
    return 0;
}