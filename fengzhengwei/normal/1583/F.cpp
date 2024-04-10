#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int n,k,a[1005][1005];
void col(int l,int r,int dp)
{
	if(r-l+1<=k)
	{
		for(int i=l;i<=r;i++)
			for(int j=i+1;j<=r;j++)a[i][j]=dp;
		return;
	}
	int val=(r-l+1+k-1)/k;
	for(int i=l;i<=r;i+=val)
	{
		col(i,min(r,i+val-1),dp+1);
		for(int s=i;s<=min(r,i+val-1);s++)
		for(int j=i+val;j<=r;j++)a[s][j]=dp;
	}
}
int main(){
	n=read(),k=read();
	col(1,n,1);
	int mx=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)mx=max(mx,a[i][j]);
	cout<<mx<<"\n";
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)cout<<a[i][j]<<" ";
	pc('1',1);
	return 0;
}