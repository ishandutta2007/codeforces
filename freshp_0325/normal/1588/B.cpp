#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F fflush(stdout)
LL n,all;
void Solve()
{
	scanf("%lld",&n);
	printf("? 1 %lld\n",n),F;
	scanf("%lld",&all);
	LL l=1,r=n,a=1;
	while(l<=r)
	{
		LL mid=(l+r)>>1,tmp;
		printf("? %lld %lld\n",mid,n),F;
		scanf("%lld",&tmp);
		if(tmp==all)	a=mid,l=mid+1;
		else	r=mid-1;;
	}
	LL st;
	printf("? %lld %lld\n",a+1,n),F;
	scanf("%lld",&st);
	LL delta=all-st;
	LL b=a+delta+1;
	l=1,r=n;
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		if((b-a)*(b-a-1)/2+mid*(mid-1)/2>all)	r=mid-1;
		else if((b-a)*(b-a-1)/2+mid*(mid-1)/2<all)	l=mid+1;
		else
		{
			printf("! %lld %lld %lld\n",a,b,b+mid-1),F;
			break;
		}
	}
}
/*
[x(x-1)+y(y-1)]/2 = all
*/
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)	Solve();
	return 0;
}
/*
(j-i)^2 + (k-j+1)^2
j^2 + i^2 - 2ij + k^2 + (j-1)^2 - 2k(j-1)
 log  i
 j/k 
 i,k 

*/