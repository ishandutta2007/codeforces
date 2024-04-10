/**
 *    author:  gary
 *    created: 01.11.2021 17:23:27
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
int n,MOD;
namespace combination
{
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
unordered_map<int,int> dp[202];
int main(){
    cin>>n>>MOD;
    genmath();
    int ans=0;
    rb(f,1,n+1){
        rb(i,1,n) dp[i].clear();
        rb(i,f*n,f+(n-1)*(n+1)){
            rb(j,max(f,(i+f-1)/f),n+1){
                dp[n][i*202+j]=1;
            }
        }
        rl(i,n,2){
            for(auto ite=dp[i].begin();ite!=dp[i].end();ite++){
                int j,k;
                j=ite->FIR/202;
                k=ite->FIR%202;
                int val=ite->SEC;
                // cout<<i<<" "<<j<<" "<<k<<" "<<val<<endl;
                rl(prej,i-1,1){
                    int s=j-(i-prej)*k;
                    if(s<0) break;
                            // cout<<prej<<" "<<s<<" "<<endl;
                    if(s>=f*prej)
                    rb(preval,max(f,(s+f-1)/f),k-1){
                        if(s>=f*(prej-1)+preval){
                            add(dp[prej][s*202+preval],1ll*val*ifact[i-prej]%MOD);
                        }
                    }
                }
            }
        }
        rb(i,1,n){
            add(ans,1ll*dp[i][i*f*202+f]*ifact[i]%MOD*fact[n]%MOD);
        }
        // cout<<f<<' '<<ans<<endl;
        // break;
    }
    cout<<ans<<endl;
    return 0;
}