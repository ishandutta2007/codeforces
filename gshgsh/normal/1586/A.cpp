#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,a[MAXN];
bool check(int x){for(int i=2;i*i<=x;i++)if(x%i==0)return 1;return 0;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];
		int sum=0;For(i,1,N)sum+=a[i];if(check(sum)){cout<<N<<'\n';For(i,1,N)cout<<i<<" \n"[i==N];continue;}
		For(i,1,N)if(a[i]&1){cout<<N-1<<'\n';For(j,1,N)if(j!=i)cout<<j<<" ";cout<<'\n';break;}
	}
	return 0;
}