#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
string s;
ll n,i,te,has;
vector<ll> isi;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(i==0||s[i]!=s[i-1])
			te=0;
		te++;
		if(i==(n-1)||s[i]!=s[i+1])
			isi.pb(te);
	}
	has=(n*(n-1))/2;
	for(i=1;i<isi.size();i++)
		has-=(isi[i-1]+isi[i]-1);
	cout<<has<<"\n";
}