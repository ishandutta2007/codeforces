#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],n;
vector<int>v;
double sum[N],out[N];
double calc(int i,int j)
{
	return (sum[j]-sum[i-1])/(j-i+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	v.emplace_back(0);
	v.emplace_back(1);
	for(int i=2;i<=n;i++)
	{
		while(1)
		{
			int k=v.size();
			if(k==1)
				break;
			if(calc(v[k-2]+1,i)<calc(v[k-2]+1,v[k-1]))
				v.pop_back();
			else
				break;
		}
		v.emplace_back(i);
	}
	for(int i=0;i<v.size()-1;i++)
	{
		double x=(sum[v[i+1]]-sum[v[i]])/(v[i+1]-v[i]);
		for(int j=v[i]+1;j<=v[i+1];j++)
			out[j]=x;
	}
	for(int i=1;i<=n;i++)
		printf("%.12lf\n",out[i]);
	return 0;
}