#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],ans[MAXN][2];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)a[i]=i;ll sum=0;For(i,1,N-1)N-i>i-1?ans[i][0]=i,ans[i][1]=N,sum+=1ll*(N-i)*(N-i),swap(a[i],a[N]):(ans[i][0]=i,ans[i][1]=1,sum+=1ll*(i-1)*(i-1),swap(a[i],a[1]));
		cout<<sum<<endl;For(i,1,N)cout<<a[i]<<' ';cout<<endl;cout<<N-1<<endl;For(i,1,N-1)cout<<ans[N-i][0]<<' '<<ans[N-i][1]<<endl;
	}
	return 0;
}