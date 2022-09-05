//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=998244353;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
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
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=100111;
const int maxk=111;
int B;
struct query
{
	int l,r,id;
	query(int L=0,int R=0,int Id=0){l=L;r=R;id=Id;}
	bool operator<(const query &t)const{return l/B==t.l/B?r<t.r:l<t.l;}
};
int n,m,q,a[maxn],all_cur[maxn],cur[maxn],ANS[maxn];
int inv[maxn*2];
int CUR_K,L,R,CURP;
void add(int x)
{
	CURP=1ll*CURP*(all_cur[a[x]]+CUR_K-cur[a[x]])%mod;
	cur[a[x]]++;
}
void del(int x)
{
	cur[a[x]]--;
	CURP=1ll*CURP*inv[all_cur[a[x]]+CUR_K-cur[a[x]]]%mod;
}
map<int,int> kid;
int tot,arr_k[maxk];
int getkid(int k)
{
	int &id=kid[k];
	if(id==0)id=++tot,arr_k[id]=k;
	return id;
}
vector<query> v[maxk];
int prod[maxn];
void prework(int K)
{
	CUR_K=K;L=1;R=0;CURP=1;
	for(int i=1;i<=m;i++)cur[i]=0;
	prod[0]=1;
	for(int i=1;i<=n;i++)prod[i]=1ll*(1ll*m*K+i)%mod*prod[i-1]%mod;
}
void solve(vector<query> v)
{
	if(!v.size())return;
	B=max(1,int(n/sqrt(v.size())));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		int l=v[i].l,r=v[i].r,id=v[i].id;
		while(L>l)add(--L);
		while(R<r)add(++R);
		while(L<l)del(L++);
		while(R>r)del(R--);
		ANS[id]=1ll*CURP*prod[n-(r-l+1)]%mod;
	}
}
void preworkc(int N)
{
	inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=-1ll*inv[mod%i]*(mod/i)%mod;
}
int main()
{
	preworkc(maxn*2);
	getiii(n,m,q);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		all_cur[a[i]]++;
	}
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		getiii(l,r,k);
		v[getkid(k)].PB(query(l,r,i));
	}
	for(int i=1;i<=tot;i++)
	{
		prework(arr_k[i]);
		solve(v[i]);
	}
	for(int i=1;i<=q;i++)putsi((ANS[i]%mod+mod)%mod);
	return 0;
}