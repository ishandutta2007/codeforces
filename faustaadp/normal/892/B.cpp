#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,hs,i,ta,a[1010101],hz;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	hs=n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[max(i-ta,1LL)]++;
		a[i]--;
	}
	for(i=1;i<=n;i++)
	{
		hz+=a[i];
		if(hz>=1)
			hs--;
	//	cout<<hz<<"\n";
	}
	cout<<hs<<"\n";
}