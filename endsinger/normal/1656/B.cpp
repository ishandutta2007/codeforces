#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
set<int>s;
void sol()
{
	s.clear();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(s.count(a[i]-k))
		{
			puts("YES");
			return;
		}
		s.insert(a[i]);
	}
	puts("NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}