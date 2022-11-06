#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,a[99],n;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>a[0]>>a[1]>>n;
		a[2]=(a[0]^a[1]);
		n%=3;
		cout<<a[n]<<"\n";
	}
}