#include<bits/stdc++.h>
using namespace std;
const int N=100005,mx=100000;
int n,m;
vector<int>x[N],y[N];
long long ans;
void sol(vector<int>&v)
{
	sort(v.begin(),v.end());
	int k=v.size();
	if(!n)
		return;
	long long s=0;
	for(int i=1;i<k;i++)
		s+=v[i]-v[0];
	for(int i=0;i<k;i++)
	{
		ans+=s;
		if(i+1<k)
		{
			s+=1ll*(i+1)*(v[i+1]-v[i]);
			s-=1ll*(k-i-1)*(v[i+1]-v[i]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int c;
			scanf("%d",&c);
			x[c].push_back(i);
			y[c].push_back(j);
		}
	}
	for(int i=1;i<=mx;i++)
	{
		sol(x[i]);
		sol(y[i]);
	}
	printf("%lld\n",ans/2);
	return 0;
}