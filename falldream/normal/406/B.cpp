#include<iostream>
#include<cstdio>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,b[MN+5],Ans[MN+5],ans=0,s[MN+5],num=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) b[read()]=1;
	for(int i=1;i<=MN/2;++i)
		if(!b[i]&&!b[MN+1-i]) s[++num]=i,s[++num]=MN+1-i;
	for(int i=1;i<=MN;++i) 
		if(b[i])
		{
			if(b[MN+1-i]) b[i]=b[MN+1-i]=0,Ans[++ans]=s[num--],Ans[++ans]=s[num--];
			else Ans[++ans]=MN+1-i;	
		}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);
	return 0;
}