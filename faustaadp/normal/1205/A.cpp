#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,te,a[202020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		for(i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				te++;
				a[i]=te;
				te++;
				a[i+n]=te;
			}
			else
			{
				te++;
				a[i+n]=te;
				te++;
				a[i]=te;
			}
		}
		for(i=1;i<=n*2;i++)
			cout<<a[i]<<" ";
	}
}