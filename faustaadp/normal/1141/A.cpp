#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,m,has,x;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	if(m%n!=0)has=-1;
	else
	{
		x=m/n;
		while(x%2==0)
		{
			has++;
			x/=2;
		}
		while(x%3==0)
		{
			has++;
			x/=3;
		}
		//cout<<n<<"\n";
		if(x!=1)has=-1;
	}
	cout<<has<<"\n";
}