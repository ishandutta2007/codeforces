#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,d[5050][10];
ll rmt(ll aa,ll bb)
{
	if(aa==n)
		return 0;
	if(d[aa][bb]==-1)
	{
		if(bb==1)
			d[aa][bb]=max(max(rmt(aa+1,1)+(s[aa]=='a'),rmt(aa+1,2)+(s[aa]=='b')),rmt(aa+1,3)+(s[aa]=='a'));
		else
		if(bb==2)
			d[aa][bb]=max(rmt(aa+1,2)+(s[aa]=='b'),rmt(aa+1,3)+(s[aa]=='a'));
		else
			d[aa][bb]=rmt(aa+1,3)+(s[aa]=='a');
	}
	return d[aa][bb];
	
}
int main()
{
	cin>>s;
	n=s.length();
	memset(d,-1,sizeof(d));
	cout<<rmt(0,1)<<"\n";
}