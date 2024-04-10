/**
 *    author:  gary
 *    created: 11.12.2021 17:55:59
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
char a[100000+10],b[100000+20];
const int MOD=998244353;
int tmp=1;
int a1,a2;
char chg(char c){
    if(c=='W') return 'A';
    return c;
}
int b1,b2;
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
int dp[4];
int main(){
    dp[0]=1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    int n;
    cin>>n;
    rb(i,1,n){
        cin>>a[i]>>b[i];
        int nw[4]={0,0,0,0};
        bool ok1,ok2;
        ok1=ok2=1;
        if(a[i]=='W'||b[i]=='B') ok1=false;
        if(a[i]=='B'||b[i]=='W') ok2=false;
        rep(mask,1<<2){
            rep(nmask,1<<2){
                if(nmask==3||nmask==0) continue;
                if(!ok1){
                    if(nmask&1) continue;
                }
                if(!ok2){
                    if(nmask&2) continue;
                }
                add(nw[nmask|mask],dp[mask]);
            }
        }
        rep(j,4) dp[j]=nw[j];
        a[i]=chg(a[i]);
        b[i]=chg(b[i]);
        if(a[i]!='?'){
            if(a[i]=='A') a[i]='B';
            else a[i]='A';
        }
        string s;
        s.PB(a[i]);
        s.PB(b[i]);
        if(s=="AB"||s=="BA"){
            tmp=0;
        }
        if((a[i]=='?')+(b[i]=='?')==2){
            tmp=1ll*tmp*2%MOD;
        }
        if(a[i]=='A') a1++;
        if(b[i]=='A') a2++;
        if(a[i]=='?') b1++;
        if(b[i]=='?') b2++;
    }
    int answer=0;
    rb(i,a1,n){
        int j=i;
        {
                add(answer,1ll*comb(b1,i-a1)*comb(b2,j-a2)%MOD);
        }
    }
    // cout<<dp[3]<<endl;
    sub(answer,dp[3]);
    cout<<answer<<endl;
    return 0;
}