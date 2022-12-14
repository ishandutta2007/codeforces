#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 4000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ans[MN+5],Ans=0,b[MN+5];
long long v[MN+5],d[MN+5],p[MN+5];
void Check(int x)
{
	if(p[x]>=0||b[x]) return;b[x]=1;
	for(int j=x+1;j<=n;++j) if(!b[j]) p[j]-=d[x];	
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) v[i]=read(),d[i]=read(),p[i]=read();
	for(int i=1;i<=n;++i) if(!b[i])
	{
		ans[++Ans]=i;
		for(int j=i+1,k=v[i];j<=n&&k;++j)
			if(!b[j]) p[j]-=k,--k;
		for(int j=i+1;j<=n;++j) Check(j);
	}
	printf("%d\n",Ans);
	for(int i=1;i<=Ans;++i) printf("%d ",ans[i]);
	return 0;
}