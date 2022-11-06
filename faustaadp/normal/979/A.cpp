#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==0)
		cout<<0<<"\n";
	else
	if(n%2==0)
		cout<<n+1<<"\n";
	else
		cout<<(n+1)/2<<"\n";
}