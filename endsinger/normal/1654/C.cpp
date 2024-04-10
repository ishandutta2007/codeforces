#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
map<int,int>c;
int sol(long long n)
{
	if(c.find(n)!=c.end()&&c[n])
	{
		c[n]--;
		return 1;
	}
	if(n==1)
		return 0;
	if(sol(n/2))
		return sol((n+1)/2);
	return 0;
}
void sol()
{
	c.clear();
	int m;
	long long n=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
		n+=x;
	}
	if(!sol(n))
		puts("NO");
	else
	{
		long long s=0;
		for(auto i:c)
			s+=i.second;
		if(s<=1)
			puts("YES");
		else
			puts("NO");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}