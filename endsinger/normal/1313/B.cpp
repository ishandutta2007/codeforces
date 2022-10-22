#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,x,y;
		cin>>n>>x>>y;
		cout<<n-max(1LL,min(n,(n-x+1)+(n-y+1)-2))+1<<' '<<min(n,x+y-1)<<endl;
	}
	return 0;
}