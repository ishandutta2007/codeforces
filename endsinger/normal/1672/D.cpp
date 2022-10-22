#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],c[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		c[i]=0;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[p])
		{
			p++;
			while(c[a[i]]&&b[p]==a[i])
			{
				c[a[i]]--;
				p++;
			}
		}
		else
			c[a[i]]++;
	}
	if(p==n+1)
		puts("YES");
	else
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