#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,K,a[MAXN];ll sum[MAXN];
int main()
{
	cin>>N>>M>>K;For(i,1,N)cin>>a[i];For(i,2,N-1)sum[i]=sum[i-1]+a[i+1]-a[i-1]-2;
	For(i,1,M){int l,r;cin>>l>>r;if(l!=r)cout<<sum[r-1]-sum[l]+K-a[r-1]-1+a[l+1]-2<<endl;else cout<<K-1<<endl;}return 0;
}