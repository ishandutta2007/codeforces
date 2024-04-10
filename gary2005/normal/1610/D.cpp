/**
 *    author:  gary
 *    created: 24.11.2021 19:48:22
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
const int MOD=1e9+7;
int n,a[MAXN];
namespace combination
{
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
int pw2[MAXN];
int solve(vector<int> v,bool pr=0){
    if(v.empty()) return 0;
    // cout<<v.size()<<endl;
    vector<int> od,ev;
    for(auto it:v){
        if(it&1) od.PB(it);
        else ev.PB(it/2);
    }
    int answer=0;
    for(int i=(pr? 2:1);i<=od.size();i+=(pr? 2:1)){
        // cout<<i<<' '<<od.size()<<endl;
        add(answer,1ll*pw2[ev.size()]*comb(od.size(),i)%MOD);
    }
    return (answer+solve(ev,1))%MOD;
}
int main(){
    pw2[0]=1;
    rb(i,1,200000) pw2[i]=(pw2[i-1]<<1)%MOD;
    genmath();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i];
    vector<int> v;
    rb(i,1,n) v.PB(a[i]);
    cout<<solve(v)<<endl;
    return 0;
}