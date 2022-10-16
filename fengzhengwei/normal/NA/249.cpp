#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int T;
const int xx=3005;
int a[xx],f[xx][xx];
int ct[xx];
int main(){
	T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				f[i][j]=1e9;
		f[n][n+1]=0;
		for(int i=n;i>=0;i--)
		{
			int re=0;
			// 
			//log 
			// 
			
			for(int j=i+1;j<=i+a[i];j++)
			{
				if(j+a[j]>i+a[i])re++;
				else ct[j+a[j]]++;
			}
			
			for(int j=i+a[i];j>=i+1;j--)
			{
				re+=ct[j],re--;// 
				f[i][j]=min(f[i][j],f[j][i+a[i]+1]+re);
				//min 
			}
			
			for(int j=i+1;j<=i+a[i];j++)
			{
				if(j+a[j]>i+a[i]);
				else ct[j+a[j]]--;
			}
			
			for(int j=n;j>=1;j--)
				f[i][j]=min(f[i][j],f[i][j+1]);
		}
		cout<<f[1][1]<<"\n";
	}
	pc('1',1);
	return 0;
}