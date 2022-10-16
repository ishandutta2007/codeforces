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
const int xx=1e6+5;
int n,f[xx],dp[xx],mx[xx],se[xx];
int main(){
	n=read()+1;
	for(int i=1;i<=n;i++)mx[i]=se[i]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=1;
		f[i]=read();
		int x=i;
//		cout<<x<<" "<<f[x]<<"!!\n";
		while(f[x])
		{
			if(dp[x]>dp[mx[f[x]]])se[f[x]]=mx[f[x]],mx[f[x]]=x;
			else if(dp[x]>dp[se[f[x]]]&&x!=mx[f[x]])se[f[x]]=x;
			x=f[x];
			if(dp[x]>=max(dp[mx[x]],dp[se[x]]+1))break;
			dp[x]=max(dp[mx[x]],dp[se[x]]+1);
//			cout<<x<<" "<<mx[x]<<" "<<se[x]<<" "<<dp[x]<<"!!\n";
		}
		cout<<dp[mx[1]]<<" \n"[i==n];
	}
	pc('1',1);
	return 0;
}