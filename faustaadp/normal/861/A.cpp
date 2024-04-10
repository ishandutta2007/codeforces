#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nn,du,li,i;
int main()
{
	cin>>n>>m;
	nn=n;
	while(n%2==0)
	{
		n=n/2;
		du++;
	}
	while(n%5==0)
	{
		n=n/5;
		li++;
	}
	for(i=du;i<m;i++)
		nn=nn*2;
	for(i=li;i<m;i++)
		nn=nn*5;
	cout<<nn<<"\n";
}