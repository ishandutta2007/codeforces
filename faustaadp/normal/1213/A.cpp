#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,x[1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		ta%=2;
		x[ta]++;
	}
	cout<<min(x[0],x[1])<<"\n";
}