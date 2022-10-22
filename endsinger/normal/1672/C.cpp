#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x=n+1,y=0;
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
			x=min(x,i),y=max(y,i);
	if(x>=y)
		puts("0");
	else
		printf("%d\n",max(1,y-x-1));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}