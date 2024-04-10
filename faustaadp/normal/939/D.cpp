#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,p[201010],n,taa,tbb;
string s1,s2;
vector<pair<char,char> > v;
ll car(ll aa)
{
	if(p[aa]==aa)
		return aa;
	else
		return car(p[aa]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i='a';i<='z';i++)
		p[i]=i;
	cin>>n;
	cin>>s1>>s2;
	for(i=0;i<n;i++)
	{
		taa=car(s1[i]);
		tbb=car(s2[i]);
		if(taa!=tbb)
		{
			v.pb(mp(s1[i],s2[i]));
		}
		p[taa]=tbb;
	}
	cout<<v.size()<<"\n";
	for(i=0;i<v.size();i++)
		cout<<v[i].fi<<" "<<v[i].se<<"\n";
}