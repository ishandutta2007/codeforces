#include<bits/stdc++.h>
#define ll long long
#define dd double
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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int a[110],b[110],n;
int mx=0;
//void ct()
//{
//	int res=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			for(int k=j+1;k<=n;k++)
//			{
//				if(a[i]+a[j]==a[k])res++;
//			}
//		}
//	}
//	if(mx<res)
//	{
//		mx=res;
//		for(int i=1;i<=n;i++)b[i]=a[i];
//	}
//}
//void dfs(int x,int y)
//{
//	if(x==n+1){return ct();}
//	for(int j=y+1;j<=20-(n-x);j++)
//		a[x]=j,dfs(x+1,j);
//}
const int xx=5e5+5;
ll tb[100005];
int k,ct[xx],ans[xx];
int main(){
	n=read();
	k=read();
	tb[1]=0,tb[2]=0;
	int op=0,now=0;
	for(int i=3;i<=n;i++)
	{
		if(op%2==0)now++;
		tb[i]=tb[i-1]+now;
		op++;
//		cout<<i<<" "<<tb[i]<<"\n";
	}
	if(k>tb[n])puts("-1"),exit(0);
	int id=0;
	for(int i=2;i<=n;i++)
		if(tb[i]<=k)id=i;
	k-=tb[id];
	for(int i=1;i<=id;i++)
		for(int j=i+1;j<=id;j++)
			ct[i+j]++;
	int tt=id;
	for(int i=1;i<=tt;i++)ans[i]=i;
	if(k)
	{
		for(int i=id+1;i;i++)
			if(ct[i]==k){ans[++tt]=i;break;}
	}
	ans[n+1]=1e9;
	for(int i=n;i>tt;i--)
		ans[i]=ans[i+1]-(ans[tt]+1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	puts("");
//	n=read();
//	dfs(1,0);
//	map<int,int>mp;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			mp[b[i]+b[j]]++;
////			cout<<b[i]+b[j]<<"\n";
//		}
//	}
//	for(auto it:mp)cout<<it.first<<" "<<it.second<<"\n";
//	dfs(1,0);
//	cout<<mx<<"\n";
//	for(int i=1;i<=n;i++)
//		cout<<b[i]<<" ";
//	puts("");
	
	pc('1',1);
	return 0;
}