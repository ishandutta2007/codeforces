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
const int mod = 998244353;
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
const int maxn = 1011;
int n;
char s[maxn];
int v[2][maxn], go[2][maxn];
vector<int> V, R;
bool vis[maxn];
void dfs(int x, int c)
{
//	cerr<<"dfs:"<<x<<","<<c<<endl;
	if (vis[x]) return;
	vis[x] = 1;
	if (go[c^1][x]!=-1) V.PB(v[c^1][x]);
	R.PB(s[x]=='?'?-1:s[x]-'0');
	if (go[c^1][x]!=-1) dfs(go[c^1][x], c^1);
}
void upd(int &x, int v) {x=(x+v)%mod;}
int calc()
{
	int dp[2] = {1, 0};
	if (R.size()==V.size()) R.PB(-1);
	assert(V.size()+1==R.size());
	for (int i=0; i<V.size(); i++)
	{
		int ndp[2] = {};
		for (int j=0; j<2; j++)
		{
			if (V[i]!=-1&&V[i]!=j) continue;
			for (int pre=0; pre<2; pre++)
			{
				if (R[i]!=-1&&R[i]!=(pre^j)) continue;
				upd(ndp[j], dp[pre]); 
			}
		}
		swap(dp, ndp);
	}
	int ret = 0;
	for (int j=0; j<2; j++)
	{
		if (R.back()!=-1&&R.back()!=j) continue;
		upd(ret, dp[j]);
	}
	return ret;
}
int solve(int l)
{
//	cerr<<"solve:"<<l<<endl;
	for (int i=0; i<n-l; i++) v[0][i] = 0, go[0][i] = -1;
	for (int i=n-l+1; i<n; i++) v[0][i] = -1;
	for (int i=n-l, j=n-1; i<n; i++, j--) go[0][i] = j;
	v[0][n-l] = v[0][go[0][n-l]] = 1;
	int ret = 1;
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<n-l; i++)
	{
		if (!vis[i])
		{
			V.clear();
			R.clear();
			dfs(i, 0);
			ret = 1ll*ret*calc()%mod;
		}
	}
	return ret;
}
int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i=0; i<n; i++) go[1][i] = n-1-i;
	memset(v[1], -1, sizeof(v[1]));
	v[1][0] = 1;
	int ans = 0;
	for (int i=1; i<n; i++) ans = (ans+solve(i))%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}