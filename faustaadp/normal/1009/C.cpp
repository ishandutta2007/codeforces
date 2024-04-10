#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,has;
ll hai(ll aa)
{
	return aa*(aa+1)/2;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		has+=ta*n;
		has+=max(tb*(hai(n/2)+hai(n/2-(n%2==0))),tb*hai(n-1));
	}
	cout<<fixed<<setprecision(15)<<(double)has/(double)n<<"\n";
}