#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int N,M,a[MAXN],pos[51];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get(),!pos[a[i]]?pos[a[i]]=i:0;
	For(i,1,M){int x=get(),y=pos[x];For(j,1,50)if(pos[j]<y)pos[j]++;printf("%d\n",y);pos[x]=1;}return 0;
}