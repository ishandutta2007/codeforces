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
struct BIT
{
	int a[maxn];
	void add(int x,int v)
	{
//		cerr<<"BIT::add:"<<x<<","<<v<<endl;
		for(int i=x;i<maxn;i+=i&(-i))a[i]+=v;
	}
	int querykth(int k)
	{
//		cerr<<"BIT::query:"<<k<<endl;
		assert(k>0);
		k--;
		int x=0,sum=0;
		for(int i=19;i>=0;i--)
		{
			if(x+(1<<i)<maxn&&sum+(1<<i)-a[x+(1<<i)]<=k)
			{
				x+=1<<i;
				sum+=(1<<i)-a[x];
			}
		}
//		cerr<<"return "<<x+1<<endl;
		return x+1;
	}
}BIT;
struct SGT
{
	struct node
	{
		int tl,tr,v;
	}a[maxn*4*20];
	#define ls a[p].tl
	#define rs a[p].tr
	int tot;
	int newnode(int q)
	{
		int p=++tot;
		a[p].tl=a[q].tl;
		a[p].tr=a[q].tr;
		a[p].v=a[q].v;
		return p;
	}
	int modify(int x,int v,int l,int r,int q)
	{
		int p=newnode(q);
		a[p].v+=v;
		if(l==r)return p;
		int m=l+r>>1;
		if(x<=m)ls=modify(x,v,l,m,a[q].tl);
		else rs=modify(x,v,m+1,r,a[q].tr);
		return p;
	}
	int K;
	int querykth(int l,int r,int qr,int ql)
	{
		int cur=(r-l+1)-(a[qr].v-a[ql].v)-(l==0);
//		cerr<<"querykth:"<<l<<","<<r<<" "<<cur<<" "<<K<<endl;
		if(cur<=K)
		{
			K-=cur;
			return r+1;
		}
		if(l==r)return l;
		int m=l+r>>1;
		int ret=querykth(l,m,a[qr].tl,a[ql].tl);
		if(ret==m+1)ret=querykth(m+1,r,a[qr].tr,a[ql].tr);
		return ret;
	}
	int query(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)return a[p].v;
		int m=l+r>>1,ret=0;
		if(x<=m)ret+=query(x,y,l,m,ls);
		if(m<y)ret+=query(x,y,m+1,r,rs);
		return ret;
	}
}sgt;
int n,m,sz;
ll a[maxn];
int b[maxn],rt[maxn];
struct seg
{
	ll p,d,cnt;
	seg(ll P=0,ll D=0,ll CNT=0){p=P;d=D;cnt=CNT;}
};
vector<seg> V;
ll pt[maxn],scnt[maxn],pid[maxn];
ll queryid(ll p)
{
	int i=upper_bound(pt,pt+sz,p)-pt-1;
	assert(i>=0&&i<sz);
	return scnt[i]+(p-V[i].p)/V[i].d;
}
pair<int,ll> queryloc(ll p)
{
	int i=upper_bound(pt,pt+sz,p)-pt-1;
	assert(i>=0&&i<sz);
	return MP(i,(p-V[i].p)%V[i].d);
}
pair<ll,ll> queryseg(ll id)
{
	int i=upper_bound(scnt,scnt+sz,id)-scnt-1;
	assert(i>=0&&i<sz);
	ll l=V[i].p+(id-scnt[i])*V[i].d;
	return MP(l,l+V[i].d);
}
void prework()
{
	ll p=1e15;
	for(int i=n;i>=1;i--)
	{
		if(p>=a[i])
		{
			ll cnt=(p-a[i])/i+1;
			V.PB(seg(p-cnt*i,i,cnt));
			p-=cnt*i;
		}
	}
	reverse(V.begin(),V.end());
	sz=V.size();
	for(int i=0;i<sz;i++)pt[i]=V[i].p;
	for(int i=1;i<=sz;i++)scnt[i]=scnt[i-1]+V[i-1].cnt;
	for(int i=n;i>=1;i--)
	{
		pair<int,ll> loc=queryloc(a[i]-1);loc.SS++;
		b[i]=BIT.querykth(loc.SS);
		BIT.add(b[i],1);
//		assert(b[i]>=1&&b[i]<=n);
		pid[i]=scnt[loc.FF];
	}
	for(int i=1;i<=n;i++)rt[i]=sgt.modify(b[i],1,0,n,rt[i-1]);
}
ll query(ll x,ll k)
{
	if(x<pt[0]||k==0)return x;
	else
	{
		pair<int,ll> xl=queryloc(x);
		pair<ll,ll> s=queryseg(queryid(x)+k);
		int ld=V[xl.FF].d;
		int rd=s.SS-s.FF;
		if(ld==rd)return xl.SS+s.FF;
//		cerr<<"ld="<<ld<<" rd="<<rd<<" K="<<xl.SS<<endl;
		sgt.K=xl.SS;
		int pos=sgt.querykth(0,n,rt[n],rt[ld]);
//		cerr<<"pos="<<pos<<endl;
		pos-=sgt.query(1,pos,0,n,rt[n])-sgt.query(1,pos,0,n,rt[rd]);
		return pos-1+s.FF;
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]),a[i]++;
//	cerr<<"a:"<<endl;
//	for(int i=1;i<=n;i++)cerr<<a[i]<<" ";cerr<<endl;
	prework();
//	for(int i=0;i<V.size();i++)cerr<<V[i].p<<","<<V[i].d<<","<<V[i].cnt<<endl;
//	for(int i=1;i<=n;i++)cerr<<queryloc(a[i]).FF<<","<<queryloc(a[i]).SS<<" ";cerr<<endl;
//	for(int i=1;i<=n;i++)cerr<<b[i]<<" ";cerr<<endl;
	for(int i=1;i<=m;i++)
	{
		ll x,k;
		getii(x,k);
		putsi(query(x,k));
	}
	return 0;
}