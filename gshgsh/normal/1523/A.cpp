#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int T,N,M,a[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N){char c;cin>>c;a[i][0]=c-'0';}a[0][0]=a[N+1][0]=0;
		while(M--){bool flag=0;For(i,1,N)if(a[i][0])a[i][1]=a[i][0];else if(a[i-1][0]+a[i+1][0]==1)a[i][1]=1,flag=1;else a[i][1]=0;if(!flag)break;For(i,1,N)a[i][0]=a[i][1];}
		For(i,1,N)cout<<a[i][0];cout<<endl;
	}
	return 0;
}