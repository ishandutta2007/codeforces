#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,a[MAXN],cnt;
int main()
{
	cin>>N>>M;For(i,1,N)cin>>a[i],cnt+=a[i];
	For(i,1,M){int opt,x;cin>>opt>>x;if(opt==1)cnt-=a[x],a[x]^=1,cnt+=a[x];else cout<<(x<=cnt)<<endl;}return 0;
}