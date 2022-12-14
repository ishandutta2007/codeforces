#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int ans=2e9,n,a[200005];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n>>1;++i) ans=min(ans,a[i+(n>>1)]-a[i]);
	cout<<ans;
	return 0;
}