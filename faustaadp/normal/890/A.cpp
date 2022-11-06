#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,a[1010],hz;
void rmt(ll aa,ll bb,ll cc)
{
	if(aa>6)
		return;
	if(bb==3&&cc*2==hz)
	{
		cout<<"YES\n";
		exit(0);
	}
	rmt(aa+1,bb+1,cc+a[aa]);
	rmt(aa+1,bb,cc);
}
int main()
{
	for(i=1;i<=6;i++)
	{
		cin>>a[i];
		hz+=a[i];
	}
	rmt(1,0,0);
	cout<<"NO\n";
}