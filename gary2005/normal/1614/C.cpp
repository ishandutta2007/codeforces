/**
 *    author:  gary
 *    created: 26.11.2021 19:02:05
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
namespace combination
{
    const int MOD=1e9+7;
    const int MAXN=200000;
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
} // namespace combination
using namespace combination;
typedef pair<int,int> mp;
int n,m;
int a[200000+20];
bool cmp(pair<mp,int>  A,pair<mp,int> B){
    return A.FIR.SEC<B.FIR.SEC;
}
int pw2[200000+29];
void solve(){
    cin>>n>>m;
    pw2[0]=1;
    rb(i,1,n) pw2[i]=(pw2[i-1]*2)%MOD,a[i]=0;
    vector<pair<mp,int> > seg(m) ;
    rep(i,m) cin>>seg[i].FIR.FIR>>seg[i].FIR.SEC>>seg[i].SEC;
    sort(ALL(seg),cmp);
    int pre[30];
    rep(i,30) pre[i]=0;
    rb(i,1,n) a[i]=0;
    rep(i,m){
        int val=seg[i].SEC;
        // cout<<seg[i].FIR.FIR<<" "<<seg[i].FIR.SEC<<" "<<seg[i].SEC<<endl;
        rep(j,30){
            if((val>>j)&1){
                if(pre[j]<seg[i].FIR.FIR){
                    pre[j]=seg[i].FIR.FIR;
                    a[seg[i].FIR.FIR]|=1<<j;
                }
            }
        }
    }
    // rb(i,1,n){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int answer=0;
    int tmp=1;
    rep(j,30){
        int cnt[2]={0,0};
        rb(i,1,n) cnt[(a[i]>>j)&1]++;
        rb(i,0,cnt[1]) if(i%2==1){
            if(i==0){
                add(answer,1ll*comb(cnt[1],i)*(pw2[cnt[0]]-1)%MOD*tmp%MOD);
            }
            else{
                add(answer,1ll*comb(cnt[1],i)*pw2[cnt[0]]%MOD*tmp%MOD);
            }
        }
        tmp=(tmp*2)%MOD;
    }
    cout<<answer<<endl;
}
int main(){
    genmath();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}