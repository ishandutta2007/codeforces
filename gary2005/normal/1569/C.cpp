/**
 *    author:  gary
 *    created: 08.09.2021 22:32:59
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
const int MAXN=2e5+1;
int n,a[MAXN];
const int MOD=998244353;
int fact[MAXN];
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    if(a[n]-a[n-1]>=2){
        puts("0");
        return ;
    }
    if(a[n]==a[n-1]){
        printf("%d\n",fact[n]);
        return ;
    }
    int cnt=0;
    rb(i,1,n) if(a[i]==a[n]-1) cnt++;
    cnt++;
    int ans=1ll*fact[n]*quick(cnt,MOD-2)%MOD;
    ans=(fact[n]-ans+MOD)%MOD;
    printf("%d\n",ans);
}
int main(){
    fact[0]=1;
    rb(i,1,200000) fact[i]=1ll*fact[i-1]*i%MOD;
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}