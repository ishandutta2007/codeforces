#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],c[101010],has;
set<ll> st;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	st.insert(n+1);
	for(i=1;i<=n;i++)
		st.insert(i);
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+n);
	for(i=1;i<=n;i++)
		c[b[i]]=i;
	for(i=1;i<=n;i++)
	{
		st.erase(c[a[i]]);
		auto it=st.begin();
		ll tem=*it;
		if(tem<=c[a[i]])
		{
			// cout<<tem<<" "<<c[a[i]]<<"_\n";
			has++;
		}
	}
	cout<<has<<"\n";
}