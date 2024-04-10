#include<bits/stdc++.h>
using namespace std;
long long n,mi,i,su,aa[200010],ab[200010],x,y;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		su=su+aa[(x-y)]+ab[x+y];
		aa[(x-y)]++;
		ab[x+y]++;
	}
	cout<<su<<endl;
}