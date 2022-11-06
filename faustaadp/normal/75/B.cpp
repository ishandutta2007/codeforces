#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
string s[9];
ll t,i,te;
pair<ll,string> A[10101];
map<string,ll> me;
string nam[10101];
ll x[999][999];
string con(string aa)
{
	return aa.substr(0,aa.length()-2);
}
ll nama(string aa)
{
	if(me[aa]==0)
	{
		me[aa]=++te;
		nam[me[aa]]=aa;
	}
	return me[aa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s[0];
	nama(s[0]);
	// return 0;
	cin>>t;
	// cout<<t<<"_\n";
	while(t--)
	{
		for(i=1;i<=4;i++)cin>>s[i];
		if(s[2]!="likes")cin>>s[5];
		else s[4]=s[3];
		if(s[2]=="posted")x[nama(s[1])][nama(con(s[4]))]+=15;
		if(s[2]=="posted")x[nama(con(s[4]))][nama(s[1])]+=15;
		if(s[2]=="commented")x[nama(s[1])][nama(con(s[4]))]+=10;
		if(s[2]=="commented")x[nama(con(s[4]))][nama(s[1])]+=10;
		if(s[2]=="likes")x[nama(s[1])][nama(con(s[4]))]+=5;
		if(s[2]=="likes")x[nama(con(s[4]))][nama(s[1])]+=5;
	}
	// return 0;
	for(i=2;i<=te;i++)
		A[i]=mp(-x[1][i],nam[i]);
	sort(A+2,A+1+te);
	for(i=2;i<=te;i++)
		cout<<A[i].se<<"\n";
}