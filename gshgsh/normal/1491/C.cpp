#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int T,N,a[MAXN],b[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],b[i]=0;
		ll ans=0;For(i,1,N){int tmp=b[i];if(tmp<a[i]-1)ans+=a[i]-1-tmp,tmp=a[i]-1;b[i+1]+=tmp-a[i]+1;For(j,i+2,min(N,i+a[i]))b[j]++;}cout<<ans<<endl;
	}
	return 0;
}