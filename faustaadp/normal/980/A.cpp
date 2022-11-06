#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,i,O;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
		if(s[i]=='o')
			O++;
	if(O==0||n%O==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
}