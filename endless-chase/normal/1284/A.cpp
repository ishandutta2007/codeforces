#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,q,x;
string s[222],t[222];
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<m;i++) cin>>t[i];
	cin>>q;
	while(q--)
	{
		cin>>x;x--;
		cout<<s[x%n]<<t[x%m]<<endl;
	}
	return Accepted;
}