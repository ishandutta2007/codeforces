#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,x,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>x;int sum=0;For(i,1,N)cin>>a[i],sum+=a[i];if(sum==x){cout<<"NO\n";continue;}
		cout<<"YES\n";sum=0;For(i,1,N){sum+=a[i];if(sum==x)swap(a[i],a[i+1]);cout<<a[i]<<' ';}cout<<endl;
	}
	return 0;
}