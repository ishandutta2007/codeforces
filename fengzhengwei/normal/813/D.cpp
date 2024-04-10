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
const int xx=5005;
int f[xx][xx],a[xx],n;
int t[100005],M[7];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int k=0;k<=n;k++)//min(ij) 
	{
		for(int i=1;i<=n;i++)t[a[i]]=0;
		for(int i=0;i<7;i++)M[i]=0;
		for(int i=1;i<k;i++)
		{
			t[a[i]]=max(t[a[i]],f[i][k]);
			M[a[i]%7]=max(M[a[i]%7],f[i][k]);
		}
		for(int i=k+1;i<=n;i++)//jk 
		{
			f[i][k]=max(max(t[a[i]+1],f[0][k]),max(t[a[i]-1],M[a[i]%7]))+1;
			t[a[i]]=max(t[a[i]],f[i][k]);
			M[a[i]%7]=max(M[a[i]%7],f[i][k]);
		}
		
		for(int i=1;i<=n;i++)t[a[i]]=0;
		for(int i=0;i<7;i++)M[i]=0;
		for(int j=1;j<k;j++)
		{
			t[a[j]]=max(t[a[j]],f[k][j]);
			M[a[j]%7]=max(M[a[j]%7],f[k][j]);
		}
		for(int j=k+1;j<=n;j++)
		{
			f[k][j]=max(max(t[a[j]+1],f[k][0]),max(t[a[j]-1],M[a[j]%7]))+1;
			t[a[j]]=max(t[a[j]],f[k][j]);
			M[a[j]%7]=max(M[a[j]%7],f[k][j]);
		}
	}
	//>max i,j 
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)ans=max(ans,f[i][j]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}