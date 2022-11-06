#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,a[1010101],hz,hs;
string s;
int main()
{
	cin>>n;
	a[1]=1;
	a[2]=1;
	a[3]=0;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(a[ta]==1)
		{
			if(a[1]==0)
			{
				a[1]=1;
				if(a[2]==1&&ta!=2)
					a[2]=0;
				else
				if(a[3]==1&&ta!=3)
					a[3]=0;
			}
			else
			if(a[2]==0)
			{
				a[2]=1;
				if(a[1]==1&&ta!=1)
					a[1]=0;
				else
				if(a[3]==1&&ta!=3)
					a[3]=0;
			}
			else
			{
				a[3]=1;
				if(a[1]==1&&ta!=1)
					a[1]=0;
				else
				if(a[2]==1&&ta!=2)
					a[2]=0;
			}
		}
		else
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}