#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,has,i;
char ct;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	has=1;
	for(i=1;i<=n;i++)
	{
		cin>>ct;
		if(ct=='1')
			has++;
		else
			break;
	}
	has=min(has,n);
	cout<<has<<"\n";
}