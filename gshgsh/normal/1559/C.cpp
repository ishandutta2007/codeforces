#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();
		if(a[1]){cout<<N+1<<' ';For(i,1,N)cout<<i<<" \n"[i==N];continue;}
		if(N==1){cout<<"1 "<<N+1<<'\n';continue;}
		int x=2;while(x<=N&&!a[x])x++;For(i,1,x-1)cout<<i<<' ';cout<<N+1<<' ';For(i,x,N)cout<<i<<' ';cout<<'\n';
	}
	return 0;
}