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
const ll Lbg=2e18;
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
int cnt1[256],cnt2[256],n;
char s[300111];
char ans[300111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)cnt1[s[i]]++;
	scanf("%s",s);
	for(int i=0;i<n;i++)cnt2[s[i]]++;
	int it1=0,it2=255;
	int lft=n/2;
	for(int i=255;i>=0;i--)
	{
		while(cnt1[i]&&lft)cnt1[i]--,lft--;
	}
	lft=(n+1)/2;
	for(int i=0;i<255;i++)
	{
		while(cnt2[i]&&lft)cnt2[i]--,lft--;
	}
	int it=0;
	bool f=0;
	for(int i=0;i<n;i++)
	{
		if(!f)
		{
			while(cnt1[it1]==0)it1++;
			while(cnt2[it2]==0)it2--;
			if(it1>=it2)
			{
				f=1;
				it1=255;
				it2=0;
				it=n-1;
			}
		}
		if(i%2==0)
		{
			if(!f)
			{
				ans[it++]=it1;
				cnt1[it1]--;
			}
			else
			{
				while(cnt1[it1]==0)it1--;
				ans[it--]=it1;
				cnt1[it1]--;
			}
		}
		else
		{
			if(!f)
			{
				ans[it++]=it2;
				cnt2[it2]--;
			}
			else
			{
				while(cnt2[it2]==0)it2++;
				ans[it--]=it2;
				cnt2[it2]--;
			}
		}
	}
	printf("%s\n",ans);
	return 0;
}