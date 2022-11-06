#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,x;
vector<ll> A[110],B[110];
vector<pair<ll,ll> > Z;
char ct;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ct;
		x=ct-'a';
		if(ct=='?')x=26;
		A[x].pb(i);
	}
	for(i=1;i<=n;i++)
	{
		cin>>ct;
		x=ct-'a';
		if(ct=='?')x=26;
		B[x].pb(i);
	}
	for(i=0;i<26;i++)
	{
		while(!A[i].empty()&&!B[i].empty())
		{
			Z.pb(mp(A[i].back(),B[i].back()));
			A[i].pop_back();
			B[i].pop_back();
		}
	}
	for(i=0;i<26;i++)
	{
		while(!A[i].empty()&&!B[26].empty())
		{
			Z.pb(mp(A[i].back(),B[26].back()));
			A[i].pop_back();
			B[26].pop_back();
		}
	}
	for(i=0;i<26;i++)
	{
		while(!A[26].empty()&&!B[i].empty())
		{
			Z.pb(mp(A[26].back(),B[i].back()));
			A[26].pop_back();
			B[i].pop_back();
		}
	}
	for(i=0;i<26;i++)
	{
		while(!A[26].empty()&&!B[26].empty())
		{
			Z.pb(mp(A[26].back(),B[26].back()));
			A[26].pop_back();
			B[26].pop_back();
		}
	}
	cout<<Z.size()<<"\n";
	for(i=0;i<Z.size();i++)
		cout<<Z[i].fi<<" "<<Z[i].se<<"\n";
}