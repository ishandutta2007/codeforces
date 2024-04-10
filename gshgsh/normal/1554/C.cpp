#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int T,N,M;int getcnt(int x,int y){}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();int l=0,r=M;
		int ans=0;FOR(i,31,0){int mid=l+(1<<i);if((N>>i)&1)if(mid+(1<<i)-1!=r)l=mid;else ans|=1<<i;else if(mid-1<=r)l=mid,ans|=1<<i;}cout<<ans
		<<endl;
	}
	return 0;
}