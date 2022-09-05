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
int n;
const int maxn = 250011;
ll pc[maxn];
int fa[maxn];
vector<ll>* dp[maxn];
vector<ll> ex[maxn];
ll getex(int x, int l)
{
	if (l>=ex[x].size()) return pc[x];
	else return ex[x][l];
}
ll getdp(int x, int l)
{
	if (l>=dp[x]->size()) return 0;
	else return (*dp[x])[l];
}
vector<ll>* merge_dp(vector<ll> *x, vector<ll> *y)
{
	if (x->size()>y->size()) swap(x, y);
	for (int i=0; i<x->size(); i++)
	{
		(*y)[i] += (*x)[i];
	}
	return y;
}
vector<pair<int,int> > con[maxn];
struct data
{
	ll sum;
	multiset<ll> A, B;
	void init()
	{
		A.clear();
		B.clear();
		sum = 0;
	}
	void insert(ll x)
	{
		if (B.size()==0||A.size()>0&&x<=*A.rbegin()) A.insert(x), sum += x;
		else B.insert(x);
	}
	void del(ll x)
	{
		if (A.find(x)!=A.end()) A.erase(A.find(x)), sum -= x;
		else B.erase(B.find(x));
	}
	void balance(int K)
	{
		while (A.size()>K) B.insert(*A.rbegin()), sum -= *A.rbegin(), A.erase(--A.end());
		while (A.size()<K&&B.size()>0) sum += *B.begin(), A.insert(*B.begin()), B.erase(B.begin());
		assert(A.size()==K);
	}
	ll getsmn() {return B.size()==0?0:*B.begin();}
}D;
void dfs(int x)
{
//	cerr<<"dfs:"<<x<<endl;
	dp[x] = new vector<ll>;
	int deg = con[x].size();
	vector<pair<int,int> > v;
	for (auto e : con[x])
	{
		int u = e.FF;
		if (u==fa[x]) continue;
		fa[u] = x;
		pc[u] = e.SS;
		dfs(u);
		v.PB(MP(ex[u].size(), u));
		dp[x] = merge_dp(dp[x], dp[u]);
	}
	ex[x].resize(deg);
	dp[x]->resize(max(deg, (int)dp[x]->size()));
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	D.init();
	for (int K=0; K<deg; K++)
	{
		for (int i=0; i<v.size()&&K<=v[i].FF; i++)
		{
			if (K>0) D.del(getex(v[i].SS, K-1));
			D.insert(getex(v[i].SS, K));
		}
		ll &cur = (*dp[x])[K];
		D.balance(deg-K-1);
		cur += D.sum;
		ll smn = D.getsmn();
		cur += min(smn, (ll)pc[x]);
		ex[x][K] = (ll)pc[x]-min(smn, (ll)pc[x]);
	}
//	cerr<<"x="<<x<<endl;
//	for (int i=0; i<=n; i++) cerr<<getdp(x, i)<<" "; cerr<<endl;
//	for (int i=0; i<=n; i++) cerr<<getex(x, i)<<" "; cerr<<endl;	
}
int main()
{
	geti(n);
	for (int i=1; i<n; i++)
	{
		int x, y, w;
		getiii(x, y, w);
		con[x].PB(MP(y, w));
		con[y].PB(MP(x, w));
	}
	pc[1] = 1e18;
	dfs(1);
	for (int i=0; i<n; i++) puti(getdp(1, i)); 
	return 0;
}