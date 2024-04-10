#include<iostream>
#include<cstdio>
#define MN 2000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool b[MN+5];
int s[MN+5],num=0,Num1[MN+5],Num2[MN+5],q[20],top;

int Solve(int x)
{
	top=0;
	for(;x;x/=10) q[++top]=x%10;
	for(int i=1,j=top;i<j;++i,--j) if(q[i]!=q[j]) return 0;
	return 1; 
}
int ans=-1,P,Q;
int main()
{
	for(int i=2;i<=MN;++i)
	{
		if(!b[i]) Num1[i]=Num1[i-1]+1,s[++num]=i;
		else Num1[i]=Num1[i-1];
		for(int j=1;s[j]*i<=MN;++j)
		{
			b[s[j]*i]=1;
			if(i%s[j]==0) break;	
		}	
	}
	for(int i=1;i<=MN;++i) Num2[i]=Num2[i-1]+Solve(i);
	P=read();Q=read();
	for(int i=1;i<=MN;++i)
		if(Num1[i]*Q<=P*Num2[i]) ans=max(ans,i);
	if(ans==MN||ans==-1) return 0*puts("Palindromic tree is better than splay tree");
	printf("%d\n",ans);
	return 0;
}