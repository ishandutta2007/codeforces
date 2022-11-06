#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[201010],h,x,hz,j,h1[201010],hv[201010];
bool bo;
int main()
{
	cin>>n;
	n++;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		h+=a[i];
	}
	for(i=1;i<n;i++)
		if(a[i]!=1&&a[i+1]!=1)
		{
			bo=1;
			x=i;
		}
			
	if(!bo)
		cout<<"perfect\n";
	else
	{
		cout<<"ambiguous\n";
		hz=1;
		for(i=1;i<n;i++)
		{
			for(j=hz+a[i];j<=hz+a[i]+a[i+1];j++)
				h1[j]=hz;
			hz+=a[i];
			hv[i]=hz;
	//		cout<<i<<" "<<hv[i]<<"\n";
		}
		hv[n]=hz+a[n];
		cout<<"0";
		for(i=2;i<=h;i++)
			cout<<" "<<h1[i];
		cout<<"\n";
		h1[hv[x+1]-1]=hv[x-1]+1;
		cout<<"0";
		for(i=2;i<=h;i++)
			cout<<" "<<h1[i];
		cout<<"\n";
	}
}