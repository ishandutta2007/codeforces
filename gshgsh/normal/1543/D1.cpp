#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get();get();
		int x=0;For(i,0,N-1){cout<<(i^x)<<endl;if(get())break;else x=i;}
	}
	return 0;
}