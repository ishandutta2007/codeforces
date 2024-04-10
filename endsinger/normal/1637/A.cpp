#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int t,n,a[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main()
{
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}