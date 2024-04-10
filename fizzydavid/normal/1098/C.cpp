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
const int maxn = 100111;
int n;
ll S;
ll check_max(ll K)
{
	ll ret = 0, mx = 1, h = 1, pw = 1, t = n;
	while (t>0)
	{
		t--;
		ret += h;
		mx--;
		if (mx==0)
		{
			h++;
			pw = pw*K;
			mx = pw;
		}
	}
	return ret;
}
ll cnt[maxn];
vector<int> id[maxn];
ll bound[maxn];
void construct(ll K)
{
//	cerr<<"construct:"<<K<<endl;
	ll lft = 1ll*n*(n+1)/2-S;
	ll pw = 1;
	for (int i=1; i<=n; i++)
	{
		bound[i] = pw-1;
		pw = min((ll)n, pw*K);
	}
	int it = 2;
	for (int i=n; i>=1; i--)
	{
		while (bound[it]==cnt[it]&&it<=i) it++;
		if (it<=i&&lft>0)
		{
			ll tmp = min((ll)i-it, lft);
			lft -= tmp;
			cnt[i-tmp]++;
		}
		else cnt[i]++;
	}
//	for (int i=1; i<=n; i++) cerr<<cnt[i]<<" "; cerr<<endl;
	ll sum = 0;
	for (int i=1; i<=n; i++)
	{
		sum += cnt[i]*i;
		if (i>1&&cnt[i]>0&&cnt[i-1]==0) assert(false);
	}
	assert(sum==S);
	int tot = 0;
//	cerr<<"K="<<K<<endl;
//	for (int i=1; i<=n; i++) cerr<<cnt[i]<<" "; cerr<<endl;
	for (int i=1; i<=n; i++)
	{
		while (cnt[i]--)
		{
			id[i].PB(++tot);
		}
		if (i>1)
		{
			int lst = K, it = 0;
			for (auto x:id[i])
			{
				puti(id[i-1][it]);
				lst--;
				if (lst==0)
				{
					lst = K;
					it++;
				}
			}
		}
		if (cnt[i]==0) break;
	}
}
int main()
{
	cin>>n>>S;
	ll L = 2*n-1, R = 1ll*n*(n+1)/2;
	if (S<L||S>R)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	ll l = 1, r = n;
	while (l<=r)
	{
		ll mid = (l+r)>>1;
		ll mn = check_max(mid);
		if (S>=mn) r = mid-1;
		else l = mid+1;
	}
	construct(l);
	return 0;
}