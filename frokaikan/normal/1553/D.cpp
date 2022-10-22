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

const int maxn = 100000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
char s[maxn+5],t[maxn+5];

bool solve()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    reverse(s+1,s+n+1);
    reverse(t+1,t+m+1);
    int ptr=1;
    rep(i,1,m)
    {
        while(ptr<=n && s[ptr]!=t[i]) ptr+=2;
        if(ptr>n) return 0;
        ptr++;
    }
    return 1;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--) puts(solve()?"YES":"NO");
    return 0;
}