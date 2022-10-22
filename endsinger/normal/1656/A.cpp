#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],d[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),d[i]=i;
	sort(d+1,d+n+1,[&](int x,int y){return a[x]<a[y];});
	printf("%d %d\n",d[1],d[n]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}