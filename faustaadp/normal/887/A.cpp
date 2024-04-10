#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n,i,hz;
bool bo;
int main()
{
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
			bo=1;
		else
		if(bo)
			hz++;
	}
	if(hz>=6)
		cout<<"yes\n";
	else
		cout<<"no\n";
}