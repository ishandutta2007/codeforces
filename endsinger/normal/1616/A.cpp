#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],s;
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<=100;i++)
		a[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[abs(x)]++;
	}
	s=(a[0]>0);
	for(int i=1;i<=100;i++)
		s+=min(a[i],2);
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}