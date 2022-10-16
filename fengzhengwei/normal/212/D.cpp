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
const int xx=1e6+5;
int n,a[xx],b[xx],pre[xx],suf[xx],stk[xx],top;
struct node
{
	int id,a;
	bool operator<(const node&w)const{return a<w.a;}
}e[xx];
ll ans[xx];
vector<pair<int,int> >v[xx];//id0/1 01 
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),e[i].id=i,e[i].a=a[i];
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)b[e[i].id]=i;
	top=1;
	for(int i=1;i<=n;i++)//b0bn+1=0 (e[i].a)
	{
		while(top&&b[stk[top]]>b[i])top--;
		pre[i]=stk[top];
		stk[++top]=i;
	}
	top=1;
	stk[top]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&b[stk[top]]>b[i])top--;
		suf[i]=stk[top];
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)v[suf[i]-i].push_back(make_pair(i,1));
	for(int i=1;i<=n;i++)v[i-pre[i]].push_back(make_pair(i,0));
	for(int i=1;i<=n;i++)v[suf[i]-pre[i]].push_back(make_pair(i,2));
	ll sum0=0,sum1=0;//sum1sum0 
	for(int i=1;i<=n;i++)sum0+=a[i];
	ans[1]=sum0;
	for(int i=2;i<=n;i++)
	{
		for(auto it:v[i-1])
		{
			if(it.second==0)sum0-=a[it.first];
			if(it.second==1)sum1+=a[it.first];
			if(it.second==2)sum1-=a[it.first];
		}
		ans[i]=ans[i-1]+sum0-sum1;
//		cout<<ans[i]<<" "<<sum0<<" ss "<<sum1<<"\n";
	}
	int q=read();
	while(q--)
	{
		int o=read();
		cout<<fixed<<setprecision(9)<<1.0*ans[o]/(n-o+1)<<"\n";
	}
	return 0;
}