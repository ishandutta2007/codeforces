#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		if(a==b)
			cout<<a<<endl;
		else if(a<b)
			cout<<(b+b/a*a)/2<<endl;
		else
			cout<<a+b<<endl;
	}
	return 0;
}