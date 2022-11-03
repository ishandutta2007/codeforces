#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n,m,a[111],mx,x;
multiset<int> s;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		s.insert(a[i]); 
	}
	for (int i=1;i<=m;i++)
	{
		x=*s.begin();
		s.erase(s.begin()); 
		s.insert(x+1);
	}
	printf("%d %d\n",*s.rbegin(),mx+m);
	return 0;
}