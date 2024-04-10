#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);if(a[1]<0){cout<<"NO\n";continue;}
		cout<<"YES\n101"<<endl;For(i,0,100)cout<<i<<' ';cout<<endl;
	}
	return 0;
}