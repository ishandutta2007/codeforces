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
int n,m;
char s[55][22];
int C[22][22],cnt1[1048576];
ll msk[22],tab1[1024],tab2[1024];
double solve(int r)
{
	for(int i=0;i<m;i++)
	{
		msk[i]=0;
		for(int j=0;j<n;j++)
		{
			if(j==r)continue;
			if(s[j][i]==s[r][i])
			{
				msk[i]|=1ll<<(j-(j>r));
			}
		}
	}
	for(int i=0;i<1024;i++)
	{
		tab1[i]=tab2[i]=(1ll<<(n-1))-1;
		for(int j=0;j<10;j++)
		{
			if((i>>j)&1)
			{
				tab1[i]&=msk[j];
				tab2[i]&=msk[j+10];
			}
		}
	}
	double ret=0;
	for(int i=0;i<(1<<m);i++)
	{
		if(tab1[i&1023]&tab2[i>>10])
		{
			ret+=1.0/C[m][cnt1[i]];
		}
	}
	return ret;
}
int main()
{
	for(int i=1;i<1048576;i++)cnt1[i]=cnt1[i-(i&(-i))]+1;
	for(int i=0;i<=20;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	m=strlen(s[0]);
	double ans=0;
	for(int i=0;i<n;i++)
	{
		double curans=solve(i)/n;
		ans+=curans;
//		cout<<i<<":"<<curans<<endl;
	}
	printf("%.10lf\n",ans);
	return 0;
}