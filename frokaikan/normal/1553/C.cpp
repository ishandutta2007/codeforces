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
char s[15],t[15];

int test(char *t)
{
    int s1=0,s2=0;
    rep(i,1,5) rep(j,1,2)
    {
        if(j==1) s1+=t[(i-1)*2+j]=='1';
        else s2+=t[(i-1)*2+j]=='1';
        int left1=5-i;
        int left2=5-i+(j==1);
        if(s1>s2+left2 || s2>s1+left1) return (i-1)*2+j;
    }
    return 10;
}   

int main()
{
    int cas; scanf("%d",&cas); while(cas--) 
    {
        scanf("%s",s+1);
        rep(i,1,10) t[i]=s[i];
        rep(i,1,10) if(t[i]=='?') t[i]=i&1?'1':'0';
        int res1=test(t);
        rep(i,1,10) t[i]=s[i];
        rep(i,1,10) if(t[i]=='?') t[i]=i&1?'0':'1';
        int res2=test(t);
        printf("%d\n",min(res1,res2));
    }
    return 0;
}