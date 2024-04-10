#include<bits/stdc++.h>
using namespace std;
set<int>s;
void add(int x)
{
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			s.insert(i);
			s.insert(x/i);
		}
	}
}
void sol()
{
	int n,m;
	scanf("%d%d",&n,&m);
	s.clear();
	add(gcd(n-1,m-1));
	add(gcd(n,m-2));
	add(gcd(n-2,m));
	add(gcd(n-1,gcd(m,m-2)));
	add(gcd(m-1,gcd(n,n-2)));
	printf("%d ",s.size());
	for(auto i:s)
		printf("%d ",i);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}