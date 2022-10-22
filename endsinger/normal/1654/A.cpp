#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,a[N],mx,cm;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mx=cm=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx)
			cm=mx,mx=a[i];
		else if(a[i]>cm)
			cm=a[i];
	}
	printf("%d\n",mx+cm);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}