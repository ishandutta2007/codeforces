//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
    char s[100000];
    int it, len;
    fastio() {it=len=0;}
    inline char get()
    {
        if (it<len) return s[it++]; it=0;
        len=fread(s, 1, 100000, stdin);
        if (len==0) return EOF; else return s[it++];
    }
    bool notend()
    {
        char c=get();
        while (c==' '||c=='\n') c=get();
        if (it>0) it--;
        return c!=EOF;
    }
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
    ll r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
    if (x<0) putchar('-'), x=-x;
    register short a[20]={}, sz=0;
    while (x) a[sz++]=x%10, x/=10;
    if(sz==0) putchar('0');
    for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}

const int inf = 1e9;
struct SGT
{
    static const int B = 1<<19;
    int a[B*2];
    int coef;
    void modify(int x, ll v)
    {
    	v = v*coef;
        x += B;
        a[x] = v;
        for (int i=x>>1; i; i>>=1)
        {
            a[i] = min(a[i<<1], a[i<<1|1]);
        }
    }
    int query(int l, int r)
    {
        if (l>r) return inf;
        l += B-1;
        r += B+1;
        int ret = inf;
        while (l^r^1)
        {
            if (~l&1) ret = min(ret, a[l^1]);
            if ( r&1) ret = min(ret, a[r^1]);
            l>>=1; r>>=1;
        }
        return ret*coef;
    }
}sgtl[20], sgtr[20];
const int maxn = 300111;
int n;
int a[maxn];
int gol[20][maxn], gor[20][maxn];
int main()
{
	geti(n);
	for (int i=1; i<=n; i++) geti(a[i]), a[i+n]=a[i+n+n]=a[i];
	if (n==1)
	{
		puts("0");
		return 0;
	}
	sgtl[0].coef = 1;
	sgtr[0].coef = -1;
	for (int i=1; i<=3*n; i++)
	{
		gol[0][i] = max(1, i-a[i]);
		gor[0][i] = min(n+n+n, i+a[i]);
		sgtl[0].modify(i, gol[0][i]);
		sgtr[0].modify(i, gor[0][i]);
	}
	for (int i=1; i<20; i++)
	{
		sgtl[i].coef = 1;
		sgtr[i].coef = -1;
		for (int j=1; j<=3*n; j++)
		{
			gol[i][j] = sgtl[i-1].query(gol[i-1][j], gor[i-1][j]);
			gor[i][j] = sgtr[i-1].query(gol[i-1][j], gor[i-1][j]);
			sgtl[i].modify(j, gol[i][j]);
			sgtr[i].modify(j, gor[i][j]);
		}
	}
	for (int i=1; i<=n; i++)
	{
		int l=n+i, r=n+i, ans=0;
		for (int t=19; t>=0; t--)
		{
			int nl = sgtl[t].query(l,r);
			int nr = sgtr[t].query(l,r);
			if (nr-nl+1<n)
			{
				l = nl;
				r = nr;
				ans += 1<<t;
			}
		}
		puti(ans+1);
	}
    return 0;
}