#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		cout<<(a+b-1)/b*b-a<<endl;
	}
	return 0;
}