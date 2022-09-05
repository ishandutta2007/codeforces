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
const int maxn=300111;
int n,k;
int pl[maxn],pr[maxn];
vector<pair<int,int> > dv[maxn];
void change_seg(int len,int pre,int cur)
{
	if(len==0)return;
	dv[cur].PB(MP(pre+1,len));
}
void prework()
{
	set<pair<int,int> > st;
	st.insert(MP(0,0));
	st.insert(MP(2e9,0));
	for(int i=1;i<=n;i++)
	{
		int l=pl[i],r=pr[i],lst=l;
		int cur=-1;
		while(true)
		{
			set<pair<int,int> >::iterator it=st.lower_bound(MP(l,0));
			if(cur==-1)cur=it->SS;
			if(it->FF<=r)
			{
				change_seg(it->FF-lst,it->SS,i);
				lst=it->FF;
				st.erase(it);
			}
			else
			{
				change_seg(r-lst,it->SS,i);
				st.insert(MP(r,i));
				break;
			}
		}
		st.insert(MP(l,cur));
	}
/*	for(int i=1;i<=n;i++)
	{
		cerr<<"i="<<i<<endl;
		for(int j=0;j<dv[i].size();j++)cerr<<dv[i][j].FF<<" "<<dv[i][j].SS<<endl;
	}*/
}
int dlt[maxn],L;
ll SUM,TOT;
int CUR;
void segadd(int x,int v)
{
	dlt[x]+=v;
	if(x<=L)
	{
		CUR+=v;
		SUM+=1ll*(L-x+1)*v;
	}
}
void incL()
{
	CUR+=dlt[++L];
	SUM+=CUR;
}
ll check(int w)
{
	memset(dlt,0,sizeof(dlt));
	L=1;CUR=SUM=TOT=0;
//	cerr<<"check:"<<w<<endl;
	ll ret=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=0;j<dv[i].size();j++)
		{
			sum+=dv[i][j].SS;
			segadd(dv[i][j].FF,dv[i][j].SS);
		}
		segadd(i+1,-sum);
		while(L<=i&&CUR>=w)incL();
		ret+=L-1;
		TOT+=SUM-CUR;
//		cerr<<i<<":"<<L<<" "<<CUR<<" "<<SUM<<" "<<TOT<<endl;
	}
	return ret;
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		getii(pl[i],pr[i]);
	}
	prework();
	int l=0,r=1e9+10;
	while(l<=r)
	{
		int m=l+r>>1;
		if(check(m)<k)r=m-1;
		else l=m+1;
	}
	ll cnt=check(r);
	assert(cnt>=k);
	ll ans=TOT-(cnt-k)*r;
	cout<<ans<<endl;
	return 0;
}