#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a,b,c,d,e,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	d=c+a;
	e=c+b;
	if(d>e)
		swap(d,e);
	if(d==e)
		has=d*2;
	else
		has=d*2+1;
	cout<<has<<"\n";
}