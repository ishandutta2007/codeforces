#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll has,n;
string s;
bool cek(ll aa)
{
	ll tem=sqrt(aa);
	tem*=tem;
	return (tem==aa);
}
void hey(string aa,ll bb)
{
	if(bb==n)
	{
		if(aa.length()!=0&&aa[0]!='0')
		{
			if(cek(stoll(aa)))
				has=min(has,n-(ll)aa.length());
		}
	}
	else
	{
		hey(aa+s[bb],bb+1);
		hey(aa,bb+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	has=1e18;
	cin>>s;
	n=s.length();
	hey("",0);
	if(has==1e18)
		has=-1;
	cout<<has<<"\n";
}