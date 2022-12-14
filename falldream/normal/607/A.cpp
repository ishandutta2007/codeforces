#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],b[MN+5],f[MN+5],ans=1e9,rk[MN+5],c[MN+5];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i) c[i]=a[rk[i]];
	for(int i=1;i<=n;++i)
	{
		int pos=lower_bound(c+1,c+n+1,a[rk[i]]-b[rk[i]])-c-1;
		f[i]=f[pos]+i-pos-1;
		ans=min(ans,f[i]+n-i);	
	}
	cout<<ans;
	return 0;
}