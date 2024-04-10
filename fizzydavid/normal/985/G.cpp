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
typedef unsigned long long ull;
ull ANS;
const int maxn=200111;
int n,m;
vector<int> con[maxn];
ull A,B,C;
ull calc_sum1(ull x,ull y){return x>y?0:(x+y)*(y-x+1)/2;}
ull calc2(ull a,ull b,vector<ull> &v)
{
	ull ret=0;
	int sz=v.size();
	for(int i=0;i<sz;i++)
	{
		ret+=a*v[i]*(sz-i-1)+b*v[i]*i;
	}
	return ret;
}
bool hs[maxn];
ull calc3(int x,int y,int z)
{
	if(x>y)swap(x,y);
	if(y>z)swap(y,z);
	if(x>y)swap(x,y);
	return x*A+y*B+z*C;
}
bool is_adj(int x,int y)
{
	for(int i=0;i<con[x].size();i++)if(con[x][i]==y)return true;
	return false;
}
int main()
{
	getii(n,m);
	getiii(A,B,C);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=0;i<n;i++)sort(con[i].begin(),con[i].end());
/*	ull TAS[4]={};
	int fac[4]={1,1,2,6};
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int cnt=is_adj(i,j)+is_adj(j,k)+is_adj(i,k);
				for(int t=0;t<=cnt;t++)
				{
					TAS[t]+=(i*A+B*j+C*k)*fac[cnt]/fac[t]/fac[cnt-t];
				}
			}
		}
	}*/
//	for(int i=0;i<4;i++)cerr<<TAS[i]<<" ";cerr<<endl;
	//Part 0
	for(ull i=0;i<n;i++)
	{
		ANS+=A*i*((n-i-1)*(n-i-2)/2);
		ANS+=B*i*i*(n-i-1);
		ANS+=C*i*(i*(i-1)/2);
	}
//	cerr<<"ANS="<<ANS<<endl;
	//Part 1
	for(ull x=0;x<n;x++)
	{
		for(ull j=0;j<con[x].size();j++)
		{
			int y=con[x][j];
			if(x>y)continue;
			ANS-=A*calc_sum1(0,x-1)+x*(B*x+C*y);
			ANS-=C*calc_sum1(y+1,n-1)+(n-y-1)*(A*x+B*y);
			ANS-=B*calc_sum1(x+1,y-1)+(y-x-1)*(A*x+C*y);
		}
	}
//	cerr<<"ANS="<<ANS<<endl;
	//Part 2
	for(ull x=0;x<n;x++)
	{
		vector<ull> v_p,v_n;
		ull cnt_p=0,cnt_n=0;
		ull sum_p=0,sum_n=0;
		for(int i=0;i<con[x].size();i++)
		{
			ull u=con[x][i];
			if(u<x)cnt_p++,sum_p+=u,v_p.PB(u);
			else cnt_n++,sum_n+=u,v_n.PB(u);
		}
		ANS+=B*x*cnt_p*cnt_n+A*x*cnt_n*(cnt_n-1)/2+C*x*cnt_p*(cnt_p-1)/2;
		ANS+=A*sum_p*cnt_n+C*sum_n*cnt_p;
		ANS+=calc2(A,B,v_p)+calc2(B,C,v_n);
	}
//	cerr<<"ANS="<<ANS<<endl;
	//Part 3
	for(ull x=0;x<n;x++)
	{
		for(int i=0;i<con[x].size();i++)hs[con[x][i]]=1;
		for(int i=0;i<con[x].size();i++)
		{
			ull y=con[x][i];
			if(MP(con[x].size(),x)>MP(con[y].size(),y))
			{
				for(int j=0;j<con[y].size();j++)
				{
					ull z=con[y][j];
					if(hs[z]&&MP(con[z].size(),z)<MP(con[x].size(),x)&&MP(con[z].size(),z)<MP(con[y].size(),y))
					{
//						cerr<<x<<","<<y<<","<<z<<" "<<calc3(x,y,z)<<endl;
						ANS-=calc3(x,y,z);
					}
				}
			}
		}
		for(int i=0;i<con[x].size();i++)hs[con[x][i]]=0;
	}
	cout<<ANS<<endl;
	return 0;
}