#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,i,ta,b[1010101],hz,hs;
void rmt(ll aa)
{
	if(aa>101)
		return ;
	b[aa]=1;
	rmt(aa+3);
	rmt(aa+7);
}
int main()
{
	cin>>t;
	rmt(0);
	while(t--)
	{
		cin>>ta;
		if(b[ta])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}