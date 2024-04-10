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
const int xx=2e5+5;
int n,b[xx],c[xx];
int t[55];
int main(){
	n=read();
	ll res=0;
	for(int i=1;i<=n;i++)b[i]=read(),res+=b[i];
	for(int i=1;i<=n;i++)c[i]=read(),res+=c[i];
	if(res%(n+n)!=0)
	{
		puts("-1");
		return 0;
	}
//	cerr<<res<<"\n";
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
//		cout<<b[i]+c[i]-res/(n+1)<<"\n";
		if(((b[i]+c[i])-res/(n+n))%n)
		{
			puts("-1");
			return 0;
		}
		ans.push_back(((b[i]+c[i])-res/(n+n))/n);
	}
	for(auto it:ans)
		for(int j=0;j<=30;j++)t[j]+=it>>j&1;
	int O=0;
	for(auto it:ans)
	{
		ll res=0;
		for(int j=0;j<=30;j++)res+=1ll*(it>>j&1)*t[j]<<j;
		if(b[++O]!=res)
		{
			puts("-1");
			return 0;
		}
	}
//	for(auto it:ans)
//	{
//		if()
//	}
	for(auto it:ans)cout<<it<<" ";
	pc('1',1);
	return 0;
}