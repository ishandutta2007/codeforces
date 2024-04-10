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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,m,k;
pair<int,int> a[555];
int vx[1011],vxn;
int vy[1011],vyn;
int getidx(int x){return lower_bound(vx,vx+vxn,x)-vx;}
int getidy(int x){return lower_bound(vy,vy+vyn,x)-vy;}
int cnt[1011][1011];
bool check(int ti)
{
//	cout<<"check:"<<ti<<endl;
	vxn=vyn=0;
	for(int i=1;i<=k;i++)
	{
		vx[vxn++]=max(1,a[i].FF-ti);
		vx[vxn++]=min(n+1,a[i].FF+ti+1);
		vy[vyn++]=max(1,a[i].SS-ti);
		vy[vyn++]=min(m+1,a[i].SS+ti+1);
	}
	vx[vxn++]=1;
	vy[vyn++]=1;
	sort(vx,vx+vxn);
	vxn=unique(vx,vx+vxn)-vx;
	sort(vy,vy+vyn);
	vyn=unique(vy,vy+vyn)-vy;
	vx[vxn]=n+1;
	vy[vyn]=m+1;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=k;i++)
	{
		int xl=getidx(max(1,a[i].FF-ti));
		int xr=getidx(min(n+1,a[i].FF+ti+1));
		int yl=getidy(max(1,a[i].SS-ti));
		int yr=getidy(min(m+1,a[i].SS+ti+1));
//		cout<<xl<<" "<<xr<<" "<<yl<<" "<<yr<<endl;
		cnt[xl][yl]++;
		cnt[xl][yr]--;
		cnt[xr][yl]--;
		cnt[xr][yr]++;
	}
/*	for(int i=0;i<vxn;i++)cout<<vx[i]<<" ";cout<<endl;
	for(int i=0;i<vyn;i++)cout<<vy[i]<<" ";cout<<endl;
	for(int i=0;i<vxn;i++)
	{
		for(int j=0;j<vyn;j++)
		{
			cout<<cnt[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int xmx=n,xmn=1,ymx=m,ymn=1;
	for(int i=0;i<vxn;i++)
	{
		for(int j=0;j<vyn;j++)
		{
			cnt[i][j]+=(i>0?cnt[i-1][j]:0)+(j>0?cnt[i][j-1]:0)-(i>0&&j>0?cnt[i-1][j-1]:0);
			if(cnt[i][j]==0&&vx[i]<=n&&vy[j]<=m)
			{
//				cout<<i<<","<<j<<endl;
				xmn=max(xmn,vx[i+1]-1-ti);
				ymn=max(ymn,vy[j+1]-1-ti);
				xmx=min(xmx,vx[i]+ti);
				ymx=min(ymx,vy[j]+ti);
			}
		}
	}
	return xmn<=xmx&&ymn<=ymx;
}
int main()
{
	getiii(n,m,k);
	for(int i=1;i<=k;i++)
	{
		getii(a[i].FF,a[i].SS);
	}
//	check(3);
//	return 0;
	int l=0,r=500000000;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}