#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>s;
	for(i=1;i<=n;i++)
		if(n%i==0)
			reverse(s.begin(),s.begin()+i);
	cout<<s<<"\n";
}