#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i=(a);i<=(n);i++)
#define per(i,a,n) for(auto i=(n);i>=(a);i--)
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
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int maxn = 1000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

char s[maxn+5],t[maxn+5];

bool solve()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    rep(i,1,n) rep(j,i,n)
    {
        if(j-i+1>m) break;
        if(j-i+1+j-1<m) continue;
        int ok=1;
        rep(k,1,m) 
        {
            int p=k<=j-i+1?i+k-1:j-(k-(j-i+1));
            if(s[p]!=t[k]) {ok=0; break;}
        }
        if(ok) return 1;
    }
    return 0;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--) puts(solve()?"YES":"NO");
    return 0;
}