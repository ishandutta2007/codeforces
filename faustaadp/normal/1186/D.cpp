#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,L[101010],R[101010],hz;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ll sl=s.length();
		string des=s.substr(sl-5,5);
		if(s[0]=='-')
		{
			ll x=stoll(s.substr(0,sl-6));
			if(des=="00000")
			{
				L[i]=x;
				R[i]=x;
			}
			else
			{
				L[i]=x-1;
				R[i]=x;
			}
		}
		else
		{
			ll x=stoll(s.substr(0,sl-6));
			if(des=="00000")
			{
				L[i]=x;
				R[i]=x;
			}
			else
			{
				L[i]=x;
				R[i]=x+1;
			}
		}	
		hz+=L[i];
	}
	for(i=1;i<=n;i++)
	{
		if(hz&&L[i]<R[i])
		{
			hz++;
			L[i]++;
		}
		cout<<L[i]<<"\n";
	}
}