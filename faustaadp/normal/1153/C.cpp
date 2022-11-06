#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,kir,kan;
char a[303030];
string z;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	if((n%2)==1)
	{
		cout<<":(\n";
		return 0;
	}
	kir=n/2;
	kan=n/2;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='(')kir--;
		if(a[i]==')')kan--;
	}
	if(kir<0||kan<0)
	{
		cout<<":(\n";
		return 0;
	}
	stack<ll> st;
	for(i=1;i<=n;i++)
	{
		if(a[i]=='(')
		{
			z+='(';
			st.push(1);
		}
		else
		if(a[i]==')')
		{
			z+=')';
			if(st.empty())
			{
				cout<<":(\n";
				return 0;
			}
			st.pop();
			if(st.empty()&&i<n)
			{
				cout<<":(\n";
				return 0;
			}
		}
		else
		{
			if(kir>0)
			{
				z+='(';
				kir--;
				st.push(1);
			}
			else
			{
				z+=')';
				kan--;
				if(st.empty())
				{
					cout<<":(\n";
					return 0;
				}
				st.pop();
				if(st.empty()&&i<n)
				{
					cout<<":(\n";
					return 0;
				}
			}
		}
	}
	if(st.empty())
	{
		cout<<z<<"\n";
	}
	else
	{
		cout<<":(\n";
		return 0;
	}
}