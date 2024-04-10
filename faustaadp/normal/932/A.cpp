#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s,z;	
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	z=s;
	reverse(z.begin(),z.end());
	s=s+z;
	cout<<s<<"\n";
}