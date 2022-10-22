#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,a[N],b[N],c[N],d[N];
vector<int>v;
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		c[i]=0;
	v.clear();
	for(int i=1;i<=n;i++)
		c[(i-a[i]+n)%n]++;
	for(int k=0;k<n;k++)
	{
		if(c[k]<n-2*m)
			continue;
		for(int i=1;i<=n;i++)
			b[i]=a[(i-1+k)%n+1],d[i]=0;
		int s=n;
		for(int i=1;i<=n;i++)
		{
			if(!d[i])
			{
				int x=i;
				s--;
				while(1)
				{
					x=b[x];
					if(d[x])
						break;
					d[x]=1;
				}
			}
		}
		if(s<=m)
			v.push_back(k);
	}
	printf("%d ",v.size());
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