#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,i,a[201010],X,Y,has,to;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	X=a[1];
	Y=a[2];
	to=k+1;
	has=X*m-(X-Y)*(m/to);
	cout<<has<<"\n";
}