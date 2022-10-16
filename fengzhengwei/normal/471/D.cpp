#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
int a[1000005];
int b[1000005];
int c[1000005];
int nxt[1000005];
signed main() {
//	freopen("a.in","r",stdin);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i]-a[i-1];
	for(int i=1;i<=m;i++)
	{
		c[i]=read();
	}
	for(int i=m;i>=1;i--)c[i]-=c[i-1];
	int p=1;
	nxt[1]=0;
	nxt[2]=1;
	for(int i=3;i<=m;i++)
	{
		while(p!=1&&c[p+1]!=c[i])p=nxt[p];
//		cout<<i<<endl;
		if(c[p+1]==c[i])p++;
		nxt[i]=p;
	}
//	cout<<"weqeqe"<<endl;
	int ans=0;
	p=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		while(p&&c[p+1]!=b[i])p=nxt[p];
		if(p==0)p=1;
		else if(c[p+1]==b[i])p++;
		if(p==m)ans++,p=nxt[p];
//		cout<<i<<" "<<p<<endl;
	}
	cout<<ans<<endl;
	return 0;
}