#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,i,d[1010],jen;
double h1,h2,he;
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(d[s[i]]==0)
		{
			jen++;
			v.pb(s[i]);
		}
		d[s[i]]++;
	}
	if(jen==1||jen>4)
		cout<<"No\n";
	else
	if(jen==4)
		cout<<"Yes\n";
	else
	if(jen==2)
	{
		if(d[v[0]]==1||d[v[1]]==1)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	else
	{
		if(s.length()==3)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}