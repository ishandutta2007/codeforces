#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,x,y,i,NOL,has;
char a[303030];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		if(a[i]=='0'&&(i==1||a[i-1]=='1'))
			NOL++;
	if(NOL==0)
		cout<<0<<"\n";
	else
	{
		has+=y;
		NOL--;
		has+=NOL*min(x,y);
		cout<<has<<"\n";
	}
}