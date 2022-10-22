#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[100005];
vector<int>v;
int find(int x)
{
	int k=x;
	double ans=x;
	for(auto i:v)
	{
		if(k%i)
			continue;
		int tot=1;
		while(k%i==0)
		{
			k/=i;
			tot++;
		}
		ans=ans*(1-1/(double)i);
	}
	if(k!=1)
		ans=ans*(1-1/(double)k);
	return ans;
}
signed main()
{
	
	for(int i=2;i<=100000;i++)
	{
		if(!p[i])
		{
			v.push_back(i);
			for(int j=i+i;j<=100000;j+=i)
				p[j]=1;
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int a,n;
		cin>>a>>n;
		int g=__gcd(a,n);
		cout<<find(n/g)<<endl;
	}
	return 0;
}