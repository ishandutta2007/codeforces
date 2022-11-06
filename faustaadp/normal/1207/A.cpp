#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,b,p,f,h,c,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>b>>p>>f;
		cin>>h>>c;
		if(h<c)
		{
			swap(p,f);
			swap(h,c);
		}
		ll dg=min(b/2,p);
		//cout<<dg<<"_\n";
		b-=(dg*2);
		has=dg*h;
		ll ay=min(b/2,f);
		has+=(ay*c);
		cout<<has<<"\n";
	}
}