//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
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
map<int,pair<int,int> > tab[31];
ll K;
int n,a[50111],sum[50111][31];
int s[31];
ll count(int msk,int lv)
{
	int lvmsk=(1<<lv)-1;
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		int cur=a[i]&(~lvmsk);
		if(i>1&&cur==(a[i-1]&(~lvmsk)))continue;
		tot+=1ll*tab[lv][cur].SS*tab[lv][cur^msk].SS;
		if(tot>K)break;
	}
	return tot;
}
ll addall(int msk,int lv)
{
	int lvmsk=(1<<lv)-1;
	ll ret=0;
	for(int i=1;i<=n;i++)
	{
		int cur=a[i]&(~lvmsk);
		if(i>1&&cur==(a[i-1]&(~lvmsk)))continue;
		pair<int,int> p=tab[lv][cur^msk];
		int r1=i+tab[lv][cur].SS-1,i2=p.FF,r2=p.FF+p.SS-1;
		for(int j=0;j<lv;j++)
		{
			int s1=sum[r1][j]-sum[i-1][j];
			int s2=sum[r2][j]-sum[i2-1][j];
			ret=(ret+(1ll*s1*(r2-i2+1-s2)+1ll*s2*(r1-i+1-s1))%mod*(1ll<<j))%mod;
		}
	}
	return ret;
}
int main()
{
	getii(n,K);K*=2;
	for(int i=1;i<=n;i++)geti(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<30;j++)
		{
			sum[i][j]+=sum[i-1][j]+((a[i]>>j)&1);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<30;j++)
		{
			pair<int,int> &p=tab[j][a[i]&(~((1<<j)-1))];
			p.SS++;
			p.FF=i;
		}
	}
	int msk=0;
	ll ans=0;
	for(int i=29;i>=0&&K>0;i--)
	{
		msk|=1<<i;
		s[i]=1;
		ll num=count(msk,i);
		if(num<=K)
		{
			K-=num;
			ans+=addall(msk,i);
			ans=(ans+1ll*msk*num)%mod;
			s[i]=0;
			msk&=~(1<<i);
		}
	}
	ans+=K*msk;
	cout<<ans%mod*((mod+1)/2)%mod<<endl;
	return 0;
}