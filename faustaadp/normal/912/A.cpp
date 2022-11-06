#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a,b,x,y,z;
int main()
{
	cin>>a>>b;
	cin>>x>>y>>z;
	cout<<max(0LL,(x*2+y)-a)+max(0LL,(y+z*3)-b)<<"\n";
}