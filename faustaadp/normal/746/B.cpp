#include<bits/stdc++.h>
using namespace std;
long long n,i,rr;
string s;
int main()
{
	cin>>n;
	cin>>s;
	rr=n-2;
	for(i=1;i<=n/2;i++)
	{
		cout<<s[rr];
		rr=rr-2;
	}
	rr=(n+1)%2;
	for(i=1;i<=n/2+(n%2);i++)
	{
		cout<<s[rr];
		rr=rr+2;
	}
	cout<<endl;
}