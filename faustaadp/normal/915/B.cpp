#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,pos,l,r;
int main()
{
	cin>>n>>pos>>l>>r;
	if(l==1&&r==n)
	{
		cout<<0<<"\n";
	}
	else
	if(l==1)
	{
		cout<<abs(r-pos)+1<<"\n";
	}
	else
	if(r==n)
	{
		cout<<abs(pos-l)+1<<"\n";
	}
	else
	{
		cout<<min(abs(r-pos)+(r-l)+2,abs(pos-l)+(r-l)+2)<<"\n";
	}
	
}