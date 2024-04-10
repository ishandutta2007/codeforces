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
struct func
{
	int ty;//E-0 T-1 F-2
	string s;
	int msk;
	func operator & (const func &t)const
	{
		func ret;
		ret.s=s+"&"+t.s;
		ret.ty=1;
		ret.msk=msk&t.msk;
		return ret;
	}
	func operator | (const func &t)const
	{
		func ret;
		ret.s=s+"|"+t.s;
		ret.ty=0;
		ret.msk=msk|t.msk;
		return ret;
	}
	func operator ! ()const
	{
		func ret;
		ret.s="!"+s;
		ret.ty=2;
		ret.msk=255-msk;
		return ret;
	}
	func addpar()
	{
		func ret;
		ret.s="("+s+")";
		ret.ty=2;
		ret.msk=msk;
		return ret;
	}
	bool operator<(const func &t)const
	{
		if(s.size()!=t.s.size())return s.size()<t.s.size();
		else return s<t.s;
	}
	func changety(int nty)
	{
		func ret;
		ret.s=s;
		ret.ty=nty;
		ret.msk=msk;
		return ret;
	}
};
map<int,func> ans;
func mn[3][256];
bool has[3][256];
func all[100111];
int tot;
void update(func x);
void addfunc(func x)
{
/*	cerr<<"addfunc:"<<endl;
	cerr<<x.s<<" "<<x.msk<<endl;
	system("pause");*/
	int tn=tot;
	all[tot++]=x;
	assert(tot<=100000);
	if(x.ty==0)
	{
		update(x.addpar());
	}
	if(x.ty==2)
	{
		update(!x);
		update(x.changety(1));
	}
	if(x.ty==1)
	{
		update(x.changety(0));
	}
	for(int i=0;i<tn;i++)
	{
		if(all[i].ty==0&&x.ty==1)
		{
			update(all[i]|x);
		}
		if(all[i].ty==1&&x.ty==0)
		{
			update(x|all[i]);
		}
		if(all[i].ty==1&&x.ty==2)
		{
			update(all[i]&x);
		}
		if(all[i].ty==2&&x.ty==1)
		{
			update(x&all[i]);
		}
	}
}
bool upd[3][256];
void update(func x)
{
	if(!has[x.ty][x.msk]||x<mn[x.ty][x.msk])
	{
		has[x.ty][x.msk]=1;
		mn[x.ty][x.msk]=x;
		upd[x.ty][x.msk]=1;
	}
}
void init()
{
	func tmp;
	tmp.ty=2;
	tmp.s="x";
	tmp.msk=240;
	addfunc(tmp);
	tmp.s="y";
	tmp.msk=204;
	addfunc(tmp);
	tmp.s="z";
	tmp.msk=170;
	addfunc(tmp);
	while(true)
	{
		bool f=0;
		for(int t=0;t<3;t++)
		{
			for(int i=0;i<256;i++)
			{
				if(upd[t][i])
				{
					addfunc(mn[t][i]);
					upd[t][i]=0;
					f=1;
				}
			}
		}
		if(!f)break;
	}
	for(int i=0;i<256;i++)
	{
		assert(has[0][i]);
		assert(has[1][i]);
		assert(has[2][i]);
		ans[i]=mn[0][i];
		ans[i]=min(ans[i],mn[1][i]);
		ans[i]=min(ans[i],mn[2][i]);
	}
}
int main()
{
	init();
	int Tn;
	geti(Tn);
	while(Tn--)
	{
		int msk=0;
		for(int i=0;i<8;i++)
		{
			char c=getreal();
			msk|=(c-'0')<<i;
		}
		printf("%s\n",(ans[msk].s).c_str());
	}
	return 0;
}