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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
unsigned f[300005],*g;
char s[300005];
signed main(){
	int n=read();
	scanf("%s",s+1);
	g=f+100000;
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='?')g--,g[0]=0;
		else 
		{
			g++;int to=min(i,n-i);
			for(int j=to;j>=-1;j--)g[j+2]+=g[j]*25;
		}
//		cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<"\n";
	}
	cout<<g[0]<<"\n";
	pc('-',1);
	return 0;
}