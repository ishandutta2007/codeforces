#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,ta,tx,tb,d[10101010],lee,t;
int main()
{
	cin>>n>>m>>t;
	if(t<=m)
		cout<<t<<"\n";
	else
	if(t>n)
		cout<<m-(t-n)<<"\n";
	else
		cout<<m<<"\n";
}