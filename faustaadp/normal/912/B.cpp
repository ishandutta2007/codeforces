#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i;
int main()
{
	cin>>n>>k;
	if(k==1)
		cout<<n<<"\n";
	else
	{
		for(i=1;i<=LLONG_MAX;i*=2)
		{
			if(i-1>=n)
			{
				cout<<i-1<<"\n";
				return 0;
			}
		}
	}
}