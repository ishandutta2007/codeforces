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
const int mod = 1e9+7;
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
const int maxn = 100111;
int r[maxn];
int go[11][11];
vector<string> v;
void prework()
{
	v.PB("");
	for (int i=1; i<10; i++)
	{
		string s;
		s.PB(char('0'+i));
		v.PB(s);
	}
	int n = 10000;
	for (int i=1; i<=n; i++)
	{
		string s = v[i];
		for (int j=0; j<i%11; j++)
		{
			v.PB(s+char('0'+j));
		}
	}
	
	for (int i=0; i<11; i++)
	{
		for (int j=0; j<11; j++)
		{
			int k = (i+1)%11;
			while (true)
			{
				(go[i][j] += k) %= 11;
				if (k==j) break;
				k = (k+1)%11;
			}
		}
	}
	r[1] = 9;
	for (int i=2; i<maxn; i++)
	{
		r[i] = (r[i-1]+go[r[i-2]][r[i-1]])%11;
	}
	r[0] = r[2];
//	for (int i=1; i<=10; i++) cerr<<r[i]<<" "; cerr<<endl;
}
bool check(string s)
{
//	cerr<<"check:"<<s<<endl;
	int k = s[0]-'0';
	for (int i=1; i<s.size(); i++)
	{
//		cerr<<"k="<<k<<endl;
		int c = s[i]-'0';
		if (c>=k) return false;
		k = (r[i]+go[r[i-1]][(k+10)%11]+c+1)%11;
	}
	return true;
}
int check(int i, int c, int k)
{
	if (c>=k) return -1;
	k = (r[i]+go[r[i^1]][(k+10)%11]+c+1)%11;
	return k;
}
char s[maxn];
ll dp[maxn][2][11];
int main()
{
	prework();
	/*
	for (auto s : v)
	{
		if (!check(s))
		{
			cerr<<"s="<<s<<endl;
			return 0;
		}
		assert(check(s));
	}
	*/
	scanf("%s", s+1);
	int n = strlen(s+1);
	ll ans = 0;
	/*
	for (int i=1; i<=n; i++)
	{
		if (s[i]=='0') continue;
		int k = s[i]-'0';
		ans++;
		for (int j=i+1; j<=n; j++)
		{
			if (!check((j-i)&1, s[j]-'0', k)) break;
			ans++;
		}
	}
	*/
	for (int i=1; i<=n; i++)
	{
		if (s[i]!='0')
		{
			dp[i][0][s[i]-'0']++;
		}
		for (int t=0; t<2; t++)
		{
			for (int k=0; k<11; k++)
			{
				ll &cur = dp[i][t][k];
				ans += cur;
				int nxt = check(t^1, s[i+1]-'0', k);
				if (nxt>=0) dp[i+1][t^1][nxt] += cur;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}