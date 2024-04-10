#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,a[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();
		int cnt0=0;For(i,1,N)cnt0+=1-a[i];if(cnt0>=N/2){cout<<N/2<<endl;For(i,1,N/2)cout<<"0 ";cout<<endl;continue;}
		int x=N/2+(N/2&1);cout<<x<<endl;For(i,1,x)cout<<"1 ";cout<<endl;
	}
	return 0;
}