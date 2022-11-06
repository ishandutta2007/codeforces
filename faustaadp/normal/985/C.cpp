#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
ll n,k,l,i,a[101010],sisa,has,isi;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>l;
	for(i=1;i<=n*k;i++)
		cin>>a[i];
	sort(a+1,a+1+(n*k));
	if(a[n]-a[1]>l)
		cout<<0<<"\n";
	else
	{
		sisa=n-1;
		has=a[1];
		isi=1;
		for(i=2;i<=n*k;i++)
		{
			if(sisa==0)
				break;
			if(isi==k||i+sisa>(n*k)||(a[i+sisa]-a[1])>l)
			{
				has+=a[i];
		//		cout<<i<<"\n";
				sisa--;
				isi=1;
			}
			else
				isi++;
		}
		//cout<<sisa<<"\n";
		cout<<has<<"\n";
	}
}