#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,t,cnt,g;
vector<pair<int,int> > v;
bool isprime(int n)
{
	for (int i=2;i<n;i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		t=i+1;
		if (t==n+1) t=1;
		v.push_back(make_pair(i,t));
	}
	cnt=n;g=1;
	while(!isprime(cnt))
	{
		cnt++;
		t=g+n/2;
		if (t>n) t-=n;
		v.push_back(make_pair(g,t));
		g++;
	}
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d %d\n",v[i].first,v[i].second);
	return Accepted;
}