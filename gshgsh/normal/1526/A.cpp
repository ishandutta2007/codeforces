#include<algorithm>
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
		cin>>N;For(i,1,N*2)cin>>a[i];sort(a+1,a+N*2+1);
		For(i,1,N)cout<<a[i]<<' '<<a[i+N]<<" \n"[i==N];
	}
	return 0;
}