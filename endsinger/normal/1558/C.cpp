#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,a[N],b[N];
vector<int>v;
void rev(int x)
{
	v.push_back(x);
	for(int i=1,j=x;i<j;i++,j--)
		swap(a[i],a[j]);
	for(int i=1;i<=n;i++)
		b[a[i]]=i;
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	v.clear();
	for(int i=1;i<=n;i++)
	{
		if((a[i]&1)!=(i&1))
		{
			puts("-1");
			return;
		}
	}
	for(int i=1;i<=n;i++)
		b[a[i]]=i;
	for(int i=n;i>=5;i-=2)
	{
		rev(b[i]);
		rev(b[i-1]-1);
		rev(b[i-1]+1);
		rev(b[i]);
		rev(i);
	}
	if(a[1]==3)
		rev(3);
	printf("%d\n",v.size());
	for(auto i:v)
		printf("%d ",i);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}