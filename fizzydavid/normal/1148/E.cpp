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
const int maxn = 300111;
int n;
pair<int,int> s[maxn];
int t[maxn];
bool vis[maxn];
int main()
{
	geti(n);
	for (int i=1; i<=n; i++) geti(s[i].FF), s[i].SS = i;
	for (int i=1; i<=n; i++) geti(t[i]);
	sort(s+1, s+n+1);
	sort(t+1, t+n+1);
	vector<pair<int,ll> > v;
	vector<pair<pair<int,int>, ll> > ans;
	for (int i=1; i<=n; i++)
	{
		if (s[i].FF<t[i])
		{
			v.PB(MP(i, t[i]-s[i].FF));
		}
		else
		{
			ll lft = s[i].FF-t[i];
			while (v.size()>0&&lft>0)
			{
				ll mn = min(v.back().SS, lft);
				lft -= mn;
				v.back().SS -= mn;
				ans.PB(MP(MP(s[v.back().FF].SS, s[i].SS), mn));
				if (v.back().SS==0) v.pop_back();
			}
			if (lft!=0)
			{
				puts("NO");
				return 0;
			}
		}
	}
    if (v.size()>0)
    {
        puts("NO");
        return 0;
    }
	puts("YES");
	putsi(ans.size());
	for (auto x : ans)
	{
		putsiii(x.FF.FF, x.FF.SS, x.SS);
	}
	return 0;
}