#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i;
string s,s2;
unordered_map<string,string> me;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s>>s2;
		s2+=";";
		s="#"+s;
		me[s2]=s;
	}
	for(i=1;i<=m;i++)
	{
		cin>>s>>s2;
		cout<<s<<" "<<s2<<" "<<me[s2]<<"\n";
	}
}