#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],f,g;
void sol()
{
	scanf("%d",&n);
	f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g=0;
		for(int j=1;j<=i&&j<=40;j++)
			if(a[i]%(j+1))
				g=1;
		if(!g)
			f=0;
	}
	puts(f?"YES":"NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}