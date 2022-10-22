#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
#define MAXM 1001
int N,a[MAXN];bool f[MAXN*MAXM];int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main()
{
	cin>>N;int sum=0;For(i,1,N)cin>>a[i],sum+=a[i];int x=a[1];For(i,2,N)x=GCD(x,a[i]);
	For(i,1,N)a[i]/=x;sum/=x;if(sum&1){cout<<0<<endl;return 0;}
	f[0]=1;For(i,1,N)FOR(j,sum/2,a[i])f[j]|=f[j-a[i]];if(!f[sum/2]){cout<<0<<endl;return 0;}
	cout<<1<<endl;For(i,1,N)if(a[i]&1){cout<<i<<endl;break;}return 0;
}