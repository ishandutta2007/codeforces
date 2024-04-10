#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
ll f[52][20005];
int sum[52][20005];
int q[20005];
int n,m,k;
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)sum[i][j]=read()+sum[i][j-1];
	for(int i=1;i<=n;i++)
	{
		ll mx=0;
		for(int j=m-k+1;j>=1;j--)
		{
			mx=max(mx,f[i-1][j+k]);
			f[i][j]=mx+sum[i][j+k-1]-sum[i][j-1];
		}
		mx=0;
		for(int j=1;j<=m-k+1;j++)
		{
			if(j>=k)mx=max(mx,f[i-1][j-k]);
			f[i][j]=max(f[i][j],mx+sum[i][j+k-1]-sum[i][j-1]);
		}
/*		for(int j=1;j<=m-k+1;j++)
		{
			cout<<i<<" "<<j<<" sss "<<f[i][j]<<"\n";
		}*/
		int l=1,r=0;
		for(int j=1;j<=m-k+1;j++)
		{
			while(l<=r&&q[l]+k<=j)l++;
			while(l<=r&&f[i-1][q[r]]-sum[i][q[r]+k-1]<f[i-1][j]-sum[i][j+k-1])r--;
			q[++r]=j;
			f[i][j]=max(f[i][j],sum[i][j+k-1]+f[i-1][q[l]]-sum[i][q[l]+k-1]);
		}
		l=1,r=0;
		for(int j=1;j<=k-1;j++)
		{
			while(l<=r&&f[i-1][q[r]]+sum[i][q[r]-1]<f[i-1][j]+sum[i][j-1])r--;
			q[++r]=j;
		}
		for(int j=1;j<=m-k+1;j++)
		{
			while(l<=r&&q[l]<=j)l++;
			while(l<=r&&f[i-1][q[r]]+sum[i][q[r]-1]<f[i-1][j+k-1]+sum[i][j+k-1-1])r--;
			q[++r]=j+k-1;
			f[i][j]=max(f[i][j],-sum[i][j-1]+f[i-1][q[l]]+sum[i][q[l]-1]);
		}
		for(int j=1;j<=m-k+1;j++)f[i][j]+=sum[i+1][j+k-1]-sum[i+1][j-1];
		
/*		for(int j=1;j<=m-k+1;j++)
		{
			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
		}*/
	}
	ll ans=0;
	for(int j=1;j<=m-k+1;j++)ans=max(ans,f[n][j]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}