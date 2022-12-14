#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char op[5];long long Ans[MN+5];
int n,m,Q,Kind[MN+5],a[MN+5],b[MN+5],B[MN+5],s[MN+5],S[MN+5],size[MN+5],Size[MN+5],mx1=1,mx2=1;
inline int getfa(int*s,int x){return s[x]?s[x]=getfa(s,s[x]):x;}
inline void Merge(int*s,int*size,int&mx,int x,int y)
{
	x=getfa(s,x);y=getfa(s,y);
	mx=max(mx,(size[x]+=size[y]));s[y]=x;
}
int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<=max(n,m);++i) size[i]=Size[i]=1;
	for(int i=1;i<=Q;++i)
	{
		scanf("%s",op+1);
		if(op[1]=='V') Kind[i]=1,b[a[i]=read()]=1;
		else Kind[i]=2,B[a[i]=read()]=1;
	}
	for(int i=1;i<n;++i) if(!b[i]) Merge(s,size,mx1,i,i+1);
	for(int i=1;i<m;++i) if(!B[i]) Merge(S,Size,mx2,i,i+1);
	for(int i=Q;i;--i)
	{
		Ans[i]=1LL*mx1*mx2;
		if(Kind[i]==1) Merge(s,size,mx1,a[i],a[i]+1);
		else Merge(S,Size,mx2,a[i],a[i]+1); 
	}
	for(int i=1;i<=Q;++i) printf("%lld\n",Ans[i]);
	return 0;
}