#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int a[200005],b[200005],s[200005],f[200005],f2[200005];
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();b[i]=read();s[i]=a[i]+b[i];
	}
	f[n+1]=2000000000;
	for(int i=n;i;i--)
	{
		f[i]=min(f[i+1]+1,s[i]);
	}
	long long ans=0;
	f2[1]=f[1];
	ans+=f2[1]-a[1];
	for(int i=2;i<=n;i++)
	{
		f2[i]=min(f2[i-1]+1,f[i]);
		if(f2[i]<a[i]||abs(f2[i]-f2[i-1])>1)
		{
			//cout<<f2[i]<<" "<<f2[i-1]<<" "<<i<<endl;
			printf("-1");
			return 0;
		}
		ans+=f2[i]-a[i];
	}
	for(int i=1;i<=n;i++){
		if(f2[i]>s[i]||f2[i]<a[i]){
			return puts("-1"),0;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<n;i++)
	{
		printf("%d ",f2[i]);
	}
	printf("%d",f2[n]);
}