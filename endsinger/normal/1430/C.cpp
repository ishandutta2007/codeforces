#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("1");
		return;
	}
	if(n==2)
	{
		puts("2");
		puts("1 2");
		return;
	}
	puts("2");
	vector<int>a;
	for(int i=1;i<=n-3;i++)
		a.push_back(i);
	a.push_back(n-1);
	a.push_back(n-1);
	printf("%d %d\n",n-2,n);
	while(a.size()>1)
	{
		int x=a.back();
		a.pop_back();
		int y=a.back();
		a.pop_back();
		printf("%d %d\n",x,y);
		a.push_back((x+y+1)/2);
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