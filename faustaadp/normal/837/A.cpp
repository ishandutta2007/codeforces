#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,hz,hs;
string s;
int main()
{
	cin>>n;
	cin.ignore();
	getline(cin,s);
	for(i=0;i<n;i++)
	{
		if(s[i]==' ')
			hz=0;
		else
		if(s[i]>='A'&&s[i]<='Z')
			hz++;
		hs=max(hs,hz);
	}
	cout<<hs<<"\n";
}