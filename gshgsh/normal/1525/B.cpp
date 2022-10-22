#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];
		bool flag=1;For(i,1,N)flag&=a[i]==i;if(flag){cout<<"0\n";continue;}
		if(a[1]==1||a[N]==N){cout<<"1\n";continue;}if(a[1]==N&&a[N]==1){cout<<"3\n";continue;}cout<<"2\n";
	}
	return 0;
}