#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,ta,te;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>ta;
		if(ta%2==0)
			ta/=2;
		else
		{
			if(ta>0)
			{
				ta/=2;
			}
			else
			{
				ta/=2;
				ta--;
			}
			if(te)ta++;
			te=1-te;				
		}
		cout<<ta<<"\n";
	}
}