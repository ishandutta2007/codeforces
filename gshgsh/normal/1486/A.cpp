#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N;ll a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];
		bool flag=1;For(i,1,N)if(a[i]<i-1){flag=0;break;}else a[i+1]+=a[i]-i+1,a[i]=i-1;cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}