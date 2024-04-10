#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],a[i]^=a[i-1];if(!a[N]){cout<<"YES\n";continue;}
		bool flag=0;For(i,1,N-2)For(j,i+1,N-1)if(a[i]==(a[j]^a[i])&&a[i]==(a[N]^a[j])){flag=1;break;}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}