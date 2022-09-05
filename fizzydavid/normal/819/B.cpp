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
int n;
ll pre1[2000111],suf1[2000111];
ll pre2[2000111],suf2[2000111];

int main()
{
	geti(n);
	for(int t=1;t<=n;t++)
	{
		int i;
		geti(i);
		i=n-i+1;
//		cout<<"i="<<i<<endl;
		int c=t-1;
		pre2[c+i-1]++;
		pre2[c+0]--;
//		cout<<c+i-1<<" "<<c<<endl;
		pre1[c+0]-=i-1;
//		cout<<c<<"-="<<i-1<<endl;
		suf2[c+i+1]++;
		suf2[c+n+1]--;
		suf1[c+n+1]-=n-i;
	}
/*	for(int i=1;i<=2*n;i++)cout<<pre2[i]<<" ";cout<<endl;
	for(int i=1;i<=2*n;i++)cout<<pre1[i]<<" ";cout<<endl;
	for(int i=1;i<=2*n;i++)cout<<suf2[i]<<" ";cout<<endl;
	for(int i=1;i<=2*n;i++)cout<<suf1[i]<<" ";cout<<endl;
*/	
	for(int i=2*n;i>=0;i--)pre2[i]+=pre2[i+1];
	for(int i=2*n;i>=0;i--)pre2[i]+=pre2[i+1];
	for(int i=2*n;i>=0;i--)pre1[i]+=pre1[i+1];
//	for(int i=1;i<=2*n;i++)cout<<pre2[i]<<" ";cout<<endl;
//	for(int i=1;i<=2*n;i++)cout<<pre1[i]<<" ";cout<<endl;
	for(int i=1;i<=2*n;i++)suf2[i]+=suf2[i-1];
	for(int i=1;i<=2*n;i++)suf2[i]+=suf2[i-1];
	for(int i=1;i<=2*n;i++)suf1[i]+=suf1[i-1];
	ll mn=1ll*mod*mod,mnid=0;
	for(int i=n;i<n+n;i++)
	{
		ll cur=pre2[i]+pre2[i-n]+pre1[i]+pre1[i-n]+suf2[i]+suf2[i-n]+suf1[i]+suf1[i-n];
//		cout<<cur<<endl;
		if(cur<mn)
		{
			mn=cur;
			mnid=i-n;
		}
	}
	if(mnid!=0)mnid=n-mnid;
	cout<<mn<<" "<<mnid<<endl;
	return 0;
}