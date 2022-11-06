#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s,z;
ll i,has;
vector<string> v;
unordered_map<string,ll> me;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	getline(cin,s);
	for(i=1;i<s.length()-1;i++)
	{
		if(s[i]==',')
			v.pb(z);
		else
		if(s[i]==' ')
			z.clear();
		else
			z+=s[i];
	}
	if(!z.empty())
		v.pb(z);
	for(i=0;i<v.size();i++)
		if(!me[v[i]])
		{
			has++;
			me[v[i]]=1;
		}
	cout<<has<<"\n";
}