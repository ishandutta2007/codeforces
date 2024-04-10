#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],hz,d[202020];
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>s;
	hz=n;
	d[n]=n;
	for(i=n-2;i>=0;i--)
	{
		if(s[i]=='0')
			hz=i+1;
		d[i+1]=hz;
		//cout<<i<<" "<<hz<<"\n";
	}
	for(i=1;i<=n;i++)
	{
//		if(b[i]==0)
		{
//			b[a[i]]=1;
//			b[i]=1;
			if(i<a[i])
			{
				if(a[i]>d[i])
				{
					cout<<"NO\n";
					return 0;
				}
			}
			if(a[i]<i)
			{
				if(i>d[a[i]])
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
}