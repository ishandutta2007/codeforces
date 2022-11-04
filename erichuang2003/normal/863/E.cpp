#include<bits/stdc++.h>
using namespace std;
int l[808080],r[808080];
int sum[808080];
int sumsum[808080];
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
		v.push_back(l[i]);
		v.push_back(r[i]);
		v.push_back(r[i]+1);
		v.push_back(l[i]-1);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)
	{
		l[i]=lower_bound(v.begin(),v.end(),l[i])-v.begin()+1;
		r[i]=lower_bound(v.begin(),v.end(),r[i])-v.begin()+1;
		sum[l[i]]++;
		sum[r[i]+1]--;
	}
	for(int i=1;i<=v.size();i++)
	{
		sum[i]+=sum[i-1];
		sumsum[i]+=sumsum[i-1];
		if(sum[i]==1)
			sumsum[i]++;
	}
	for(int i=1;i<=n;i++)
		if(sumsum[r[i]]==sumsum[l[i]-1])
		{
			printf("%d\n",i);
			return 0;
		}
	puts("-1");
	return 0;
}