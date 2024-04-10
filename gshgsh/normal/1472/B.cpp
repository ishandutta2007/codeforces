#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int sum=0,cnt1=0,cnt2=0;For(i,1,N)cin>>a[i],sum+=a[i],(a[i]==1?cnt1:cnt2)++;
		if(sum&1){cout<<"NO\n";continue;}if((sum>>1)&1){cout<<(cnt1?"YES\n":"NO\n");continue;}cout<<"YES\n";
	}
	return 0;
}