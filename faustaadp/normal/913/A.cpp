#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,hz,i;
int main()
{
	cin>>n>>m;
	hz=1;
	for(i=1;i<=n;i++)
	{
		hz=hz*2;
		if(hz>m)
		{
			cout<<m<<"\n";
			return 0;
		}
	}
	cout<<m%hz<<"\n";
}