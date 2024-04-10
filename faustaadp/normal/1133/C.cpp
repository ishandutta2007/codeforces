#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[202020],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		ll L=i,R=n,C;
		while(L<=R)
		{
			C=(L+R)/2;
			if(a[i] + 5 >= a[C])
			{
				has=max(has,C-i+1);
				L=C+1;
			}
			else
				R=C-1;
		}
	}
	cout<<has<<"\n";
}