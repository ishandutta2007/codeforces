#include<cstdio>
using namespace std;
long long n,q;
int main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=q;i++)
	{
		long long x;
		scanf("%lld",&x);
		long long tot=n,flag=0,rank=x,roundnum=n;
		while(x%2==0)
		{
//			printf("x=%lld rank=%lld tot=%lld roundnum=%lld\n",x,rank,tot,roundnum);
			rank=(tot-roundnum)%2 ? (rank+1)/2 : rank/2; 
			x=tot+rank;
			roundnum=tot%2 ? roundnum/2 : (roundnum+1)/2; 
			tot+=roundnum;
		}
		printf("%lld\n",(x+1)/2);
	}
}