#include<bits/stdc++.h>
using namespace std;
int n,x,v;
multiset<int>s;
void sol()
{
	scanf("%d%d",&n,&x);
	v=0;
	s.clear();
	for(int i=1;i<=n;i++)
	{
		int z;
		scanf("%d",&z);
		s.insert(-z);
	}
	while(s.size())
	{
		int z=*s.begin();
		s.erase(s.begin());
		if(z%x)
			v++;
		else if(s.count(z/x))
			s.erase(s.find(z/x));
		else
			v++;
	}
	printf("%d\n",v);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}