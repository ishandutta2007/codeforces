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
bitset<10011> dp0[111][111], dp1[111][111];
bool check(int l, int r, int k, int sum)
{
	for (int i=0; i<=k; i++)
	{
		for (int j=0; j<=sum; j++)
		{
			if (dp0[l][i][j]&&dp1[r][k-i][sum-j]) return true;
		}
	}
	return false;
}
int n;
vector<int> v;
int cnt[111], a[111];
void prework()
{
	dp0[0][0][0] = 1;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<i; j++)
		{
			dp0[i][j+1] |= dp0[i-1][j]<<a[i];
			dp0[i][j] |= dp0[i-1][j];
		}
	}
	dp1[n+1][0][0] = 1;
	for (int i=n; i>=1; i--)
	{
		for (int j=0; j<=n-i; j++)
		{
			dp1[i][j+1] |= dp1[i+1][j]<<a[i];
			dp1[i][j] |= dp1[i+1][j];
		}
	}
}
int main()
{
	geti(n);
	int tot=0;
	for (int i=1; i<=n; i++)
	{
		int x;
		geti(x);
		tot += !cnt[x];
		cnt[x]++;
		a[i] = x;
	}
	sort(a+1, a+n+1);
	prework();
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		int l = i, r = i;
		while (r<=n&&a[r]==a[i]) r++;
		while (l>1&&a[l-1]==a[i]) l--;
		if (!check(i-1, r, i-l+1, (i-l+1)*a[i]))
		{
			if (tot==2&&l==1&&r==i+1) ans = max(ans, n);
			else ans = max(ans, i-l+1);
		}
	}
	cout<<ans<<endl;
    return 0;
}