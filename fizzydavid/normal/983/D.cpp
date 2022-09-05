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
const int mod=1e9+7;
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
int n;
vector<int> vy;
int getidy(int y){return upper_bound(vy.begin(),vy.end(),y)-vy.begin();}
bool ANS[100111];
struct node
{
	set<int> st;
	int mn,mx;
	int cmxu,hmxu;
	void add(int x){st.insert(x);mx=*st.rbegin();}
	void del(int x){st.erase(x);assert(st.size()>0);mx=*st.rbegin();}
	node(){add(0);cmxu=hmxu=mn=0;}
	void query(int x){if(mx>=x)ANS[mx]=1;}
}a[800111];
#define ls p<<1
#define rs p<<1|1
void updateu(int p)
{
	a[p].cmxu=max(a[p>>1].cmxu,a[p].mx);
}
void update(int p,bool isl)
{
	a[p].mn=max(a[p].mx,(isl?0:min(a[ls].mn,a[rs].mn)));
}
void deltag(int p,bool isl)
{
	a[p].query(max(a[p].mn,max(a[p].hmxu,a[p].mx)));
	if(!isl)
	{
		int cmxu=max(a[p].hmxu,a[p].mx);
		a[ls].hmxu=min(a[ls].hmxu,cmxu),a[rs].hmxu=min(a[rs].hmxu,cmxu);
	}
	a[p].hmxu=a[p>>1].cmxu;
}
void modify(int x,int y,int op,int v,int l,int r,int p=1)
{
	deltag(p,l==r);
	updateu(p);
	if(x<=l&&r<=y)
	{
		if(op==1)a[p].add(v);else a[p].del(v);
		updateu(p);
		update(p,l==r);
		if(l<r)
		{
			a[ls].hmxu=min(a[ls].hmxu,a[p].cmxu);
			a[rs].hmxu=min(a[rs].hmxu,a[p].cmxu);
		}
		a[p].query(max(a[p].mn,a[p].cmxu));
		return;
	}
	int m=l+r>>1;
	if(x<=m)modify(x,y,op,v,l,m,ls);
	if(m<y)modify(x,y,op,v,m+1,r,rs);
	update(p,l==r);
	a[p].query(max(a[p].mn,a[p].cmxu));
}
struct query
{
	int op,x,yl,yr,id;
	bool operator<(const query &t)const{return MP(MP(x,op),op==1?-id:id)<MP(MP(t.x,t.op),t.op==1?-t.id:t.id);}
};
vector<query> qr;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int xl,yl,xr,yr;
		getii(xl,yl);
		getii(xr,yr);
		yr--;
		vy.PB(yl);vy.PB(yr+1);
		query tmp;tmp.yl=yl;tmp.yr=yr;tmp.id=i;
		tmp.x=xl;tmp.op=1;qr.PB(tmp);
		tmp.x=xr;tmp.op=2;qr.PB(tmp);
	}
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
//	for(auto x:vy)cout<<x<<" ";cout<<endl;
	sort(qr.begin(),qr.end());
	int sz=vy.size();
	for(int i=0;i<qr.size();i++)
	{
		int yl=getidy(qr[i].yl);
		int yr=getidy(qr[i].yr);
//		cerr<<qr[i].op<<" "<<yl<<","<<yr<<" "<<qr[i].id<<endl;
		modify(yl,yr,qr[i].op,qr[i].id,1,sz);
//		for(auto x:ANS)cerr<<x<<" ";cerr<<endl;
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans+=ANS[i];
	cout<<ans<<endl;
	return 0;
}