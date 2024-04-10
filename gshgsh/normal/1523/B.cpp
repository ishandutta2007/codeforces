#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();
		cout<<N*3<<endl;For(i,1,N/2){int x=i*2-1,y=i*2;For(j,1,3)cout<<"2 "<<x<<' '<<y<<"\n1 "<<x<<' '<<y<<endl;}
	}
	return 0;
}