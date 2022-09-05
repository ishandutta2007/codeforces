//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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

const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n;
int dp[100111][2];
/*
0 white
1 black
*/
vector<int> con[100111];
int ans = 1;
void dfs(int x, int pre=-1)
{
	int sz = con[x].size()-(pre!=-1);
	dp[x][0] = sz;
	dp[x][1] = 1;
	for (auto u : con[x])
	{
		if (u==pre)continue;
		dfs(u, x);
		dp[x][0] = max(dp[x][0], dp[u][0]+sz-1);
		dp[x][0] = max(dp[x][0], dp[u][1]+sz-1);
		dp[x][1] = max(dp[x][1], dp[u][0]+1);
	}
	ans = max(ans, dp[x][1]);
	ans = max(ans, dp[x][0]+(pre!=-1));
	//white root
	vector<int> v;
	for (auto u : con[x])
	{
		if (u==pre)continue;
		v.PB(max(dp[u][0]-1, dp[u][1]-1));
	}
	v.PB(0);
	v.PB(0);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ans = max(ans, v[0]+v[1]+int(con[x].size()));
	//black root
	v.clear();
	for (auto u : con[x])
	{
		if (u==pre)continue;
		v.PB(dp[u][0]);
	}
	v.PB(0);
	v.PB(0);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ans = max(ans, v[0]+v[1]+1);
//	cerr<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
}
int main()
{
	geti(n);
	for (int i=1; i<n; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for (int i=1; i<=n; i++) ans = max(ans, (int)con[i].size());
	dfs(1);
	cout<<ans<<endl;
	return 0;
}