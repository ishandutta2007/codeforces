#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>b*c)
		{
			cout<<-1<<endl;
			continue;
		}
		if(d>c)
		{
			cout<<a<<endl;
			continue;
		}
		c=a/b;
		int x=c/d;
		int k=-d*x*(x+1)/2*b;
		k+=(x+1)*a;
		cout<<k<<endl;
	}
	return 0;
}