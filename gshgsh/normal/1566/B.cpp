#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		string x;cin>>x;N=x.length();For(i,1,N)a[i]=x[i-1]-'0';
		int cnt=0;For(i,1,N)if(!a[i]&&(i==1||a[i]!=a[i-1]))cnt++;
		cout<<min(cnt,2)<<'\n';
	}
	return 0;
}