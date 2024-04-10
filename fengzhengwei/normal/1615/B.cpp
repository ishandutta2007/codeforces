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
const int xx=2e5+5;
int sum[35][xx];
int main(){
	for(int t=0;t<=30;t++)
	{
		for(int i=1;i<xx;i++)
		sum[t][i]=sum[t][i-1]+(i>>t&1);
	}
	int T=read();
	while(T--)
	{
		int l=read(),r=read();
		int mx=0;
		for(int t=0;t<=30;t++)
			mx=max(mx,sum[t][r]-sum[t][l-1]);
		cout<<(r-l+1)-mx<<"\n";
	}
	pc('1',1);
	return 0;
}