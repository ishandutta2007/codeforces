#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n;
string s;
map<string,ll> me;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(me[s])cout<<"YES\n";
		else cout<<"NO\n";
		me[s]=1;
	}
}