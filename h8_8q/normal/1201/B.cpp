#include<cstdio>
#include<iostream>

using namespace std;

long long n,all,mmax,temp,i,j;

int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		all+=temp;
		mmax=max(mmax,temp);
	}
	if(all%2==0&&mmax<=all-mmax)printf("YES");
	else printf("NO");
	return 0;
}