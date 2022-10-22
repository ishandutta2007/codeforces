/**
 *    author:  gary
 *    created: 30.09.2022 22:31:59
**/
#include<bits/stdc++.h>
// #include<atcoder/convolution>
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
// using namespace atcoder;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
namespace combination
{
    const int MOD=998244353;
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
}
using namespace combination;
int calc(int x,int y){
    int s=0;
    rb(i,0,min(x,y)){
        add(s,1ll*comb(x,i)*comb(y,i)%MOD);
    }
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        vector<LL> suf(n+2,0),pre(n+2,0);
        rep(i,n){
            cin>>a[i+1];
        }
        rb(i,1,n){
            pre[i]=pre[i-1]+a[i];
        }
        rl(i,n,1){
            suf[i]=suf[i+1]+a[i];
        }
        map<LL,int> L,R;
        vector<int> v;
        rb(i,1,n) if(pre[i]==suf[i]) v.push_back(i);
        rb(i,1,n) {
            if(v.size()&&a[v[0]]==0&&(i==v[0]-1||i==v.back()+1)) continue;
            if(pre[i]!=suf[i]){
                if(pre[i]<suf[i]) L[pre[i]]++;
                else R[suf[i]]++;
            }
        }
        int ans=1;
        for(auto it:L){
            ans=1ll*ans*calc(it.second,R[it.first])%MOD;
        }
        if(v.size()==0);
        else{
            if(a[v[0]]==0){
                int cnt=0;
                if(v[0]!=1) cnt++;
                if(v.back()!=n) cnt++;
                rb(i,1,cnt) v.push_back(0);
            }
            int s=0;
            rb(i,0,v.size()/2){
                add(s,comb(v.size(),2*i));
            }
            ans=1ll*ans*s%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}