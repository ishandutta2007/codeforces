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
vector<int> a[3];
void input(int n, vector<int> &v)
{
	v.clear();
	for (int i=0; i<n; i++)
	{
		int x;
		geti(x);
		v.PB(x);
	}
	sort(v.begin(), v.end());
}
ll ANS;
void upd(ll x, ll y, ll z)
{
	ANS = min(ANS, (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
}
void solve(int x, int y, int z)
{
	int itx=0, itz=0;
	for (int i=0; i<a[y].size(); i++)
	{
		ll cur = a[y][i];
		while (itx+1<a[x].size()&&a[x][itx+1]<=cur) itx++;
		while (itz<a[z].size()&&a[z][itz]<cur) itz++;
		if (itx<a[x].size()&&a[x][itx]<=cur&&itz<a[z].size())
		{
			upd(a[x][itx], cur, a[z][itz]);
		}
	}
}
void solve()
{
	int n1, n2, n3;
	getiii(n1, n2, n3);
	input(n1,a[0]);
	input(n2,a[1]);
	input(n3,a[2]);
	ANS = 5e18;
	solve(0, 1, 2);
	solve(0, 2, 1);
	solve(1, 0, 2);
	solve(1, 2, 0);
	solve(2, 1, 0);
	solve(2, 0, 1);
	cout<<ANS<<endl;
}
int tn;
int main()
{
	geti(tn);
	while(tn--)solve();
	return 0;
}