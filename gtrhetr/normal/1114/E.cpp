#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;

inline int gcd(int x,int y) { return (!y)?x:gcd(y,x%y); }

int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	int l=0,r=1000000000;
	int hh=0;
	while (l<r)
	{
		int mid=(l+r)>>1;
		printf("> %d\n\n",mid);fflush(stdout);
		hh++;
		int x;scanf("%d",&x);
		if (x==0) r=mid;
		else l=mid+1;
	}
	int mx=l;
	int res=0;
	for (int i=1;i<=60-hh;i++)
	{
		ll x=rand()*rand()%n+1;
		printf("? %I64d\n\n",x);fflush(stdout);
		int y;scanf("%d",&y);y=mx-y;
		if (y==0) continue;
		if (!res) res=y;
		else res=gcd(res,y);
	}
	printf("! %d %d\n",mx-res*(n-1),res);
	return 0;
}