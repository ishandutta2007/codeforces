#include<bits/stdc++.h>
using namespace std;
long long n,i,j;
string s;
bool pal(long long pi)
{
	for(i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1]&&i!=pi)
		{
		//	cout<<"NO\n";
			return 0;
		}
	}
	return 1;
}
int main()
{
	
	cin>>s;
	n=s.length();
	if(pal(-1)==1&&n%2==0)
	{
		cout<<"NO\n";
		return 0;
	}
	for(j=0;j<=n/2;j++)
	{
		if(pal(j))
		{
			//cout<<j<<endl;
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}