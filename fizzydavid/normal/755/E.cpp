//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,k;
int main()
{
	cin>>n>>k;
	if(n<=3)
	{
		cout<<-1<<endl;
		return 0;
	}
	else if(n>=5&&k==2)
	{
		printf("%d\n",n-1);
		for(int i=1;i<=n-1;i++)printf("%d %d\n",i,i+1);
	}
	else if(k==3)
	{
		if(n==4)
		{
			printf("%d\n",n-1);
			for(int i=1;i<=n-1;i++)printf("%d %d\n",i,i+1);
		}
		else if(n==5)
		{
			printf("%d\n",n);
			for(int i=1;i<=n-1;i++)printf("%d %d\n",i,i+1);
			puts("1 3");
		}
		else
		{
			int t1=(n+1)/2,t2=n/2;
			printf("%d\n",t1*(t1-1)/2+t2*(t2-1)/2+1);
			puts("1 2");
			for(int i=1;i<=n;i+=2)for(int j=i+2;j<=n;j+=2)printf("%d %d\n",i,j);
			for(int i=2;i<=n;i+=2)for(int j=i+2;j<=n;j+=2)printf("%d %d\n",i,j);
		}
	}
	else puts("-1");
	return 0;
}