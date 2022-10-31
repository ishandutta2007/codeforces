#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long i, j, n, k, a[100007], v1, v2, iol, p;
vector<int> v[100007];
int main()
{
	p=500007;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		cin>>j;
		v[j].push_back(i);
	}
	for(j=1; j<=100004; j++)
	{
		v1=v[j].size();
		v2=v[j+1].size();
		if(v1*(k-1)<v2)
		{
			iol++;
		}
	}
	v1=v[0].size();
	v2=v[1].size();
	if(v1*k<v2)
	{
		iol++;
	}
	if(v1!=1)
	{
		iol++;
	}
	if(iol!=0)
	{
		cout<<-1;
	}
	else
	{
		for(i=0; i<v[1].size(); i++)
		{
			a[v[1][i]]=v[0][0];
		}
		for(j=2; j<100004; j++)
		{
			for(i=0; i<v[j].size(); i++)
			{
				a[v[j][i]]=v[j-1][(i%v[j-1].size())];
			}
		}
		cout<<n-1<<endl;
		for(i=1; i<=n; i++)
		{
			if(i!=v[0][0])
			{
				cout<<i<<' '<<a[i]<<endl;
			}
		}
	}





}