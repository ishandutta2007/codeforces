#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

//header

ll fac[maxn+5],inv[maxn+5],ifac[maxn+5];
char s[maxn+5];

ll binom(int n,int m)
{
    if(m<0 || n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main()
{
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        scanf("%s",s+1);
        int N=0,z=0,one=0;
        rep(i,1,n) z+=s[i]=='0';
        rep(i,1,n)
        {
            if(s[i]=='1') 
            {
                if(one==0) one=1;
                else one=0,N++;
            }
            else one=0;
        }
        if(N==0 || z==0) {puts("1"); continue;}
        int ans=0;
        rep(i,1,z+1)
        {
            ans=(ans+binom(z+1,i)*binom(N-1,i-1))%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}