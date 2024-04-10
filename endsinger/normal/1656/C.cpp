#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
set<int>s;
void sol()
{
	s.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	if(!s.count(1))
		puts("YES");
	else
	{
		for(auto i:s)
		{
			if(s.count(i+1))
			{
				puts("NO");
				return;
			}
		}
		puts("YES");
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