//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m,k;
int c[200111];
bool fa[200111],fb[200111];
vector<ll> v[4],s[4];
int main()
{
	getiii(n,m,k);
	for(int i=1;i<=n;i++)geti(c[i]);
	int nn;
	geti(nn);
	while(nn--){int x;geti(x);fa[x]=1;}
	geti(nn);
	while(nn--){int x;geti(x);fb[x]=1;}
	for(int i=1;i<=n;i++)v[fa[i]<<1|fb[i]].PB(c[i]);
	for(int i=0;i<4;i++)
	{
		v[i].PB(0);
		sort(v[i].begin(),v[i].end());
		s[i].PB(0);
		for(int j=1;j<v[i].size();j++)s[i].PB(s[i][j-1]+v[i][j]);
	}
	ll ans=Lbig;
	for(int i=0;i<=m&&i<v[3].size();i++)
	{
//		cout<<"i="<<i<<endl;
		ll cost=s[3][i];
		int p=max(0,k-i);
		if(p>=v[1].size()||p>=v[2].size()||i+p*2>m)continue;
		int lft=m-i-p*2;
//		cout<<"lft="<<lft<<" p="<<p<<endl;
		int l=0,r=mod;
		while(l<=r)
		{
			int m=l+r>>1;
			int p0=upper_bound(v[0].begin(),v[0].end(),m)-v[0].begin()-1;
			int p1=max(p,int(upper_bound(v[1].begin(),v[1].end(),m)-v[1].begin())-1);
			int p2=max(p,int(upper_bound(v[2].begin(),v[2].end(),m)-v[2].begin())-1);
			if(p0+p1+p2-p-p>=lft)r=m-1;else l=m+1;
		}
		if(l>=mod)continue;
//		cout<<"l="<<l<<endl;
		int m=l;
		int p0=upper_bound(v[0].begin(),v[0].end(),m)-v[0].begin()-1;
		int p1=max(p,int(upper_bound(v[1].begin(),v[1].end(),m)-v[1].begin())-1);
		int p2=max(p,int(upper_bound(v[2].begin(),v[2].end(),m)-v[2].begin())-1);
		cost+=s[0][p0];
		cost+=s[1][p1];
		cost+=s[2][p2];
		cost-=1ll*(p0+p1+p2-p-p-lft)*max(max(v[0][p0],p1==p?0:v[1][p1]),p2==p?0:v[2][p2]);
		ans=min(ans,cost);
	}
	if(ans==Lbig)puts("-1");else putsi(ans);
	return 0;
}