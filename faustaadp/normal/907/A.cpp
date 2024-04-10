#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d,e;
int main()
{
	cin>>a>>b>>c>>d;
	if(max(c,d)<=min(2*c,2*d))
		e=max(c,d);
	if(e==0||e>=b)
		cout<<-1<<"\n";
	else
		cout<<2*a<<" "<<2*b<<" "<<e<<"\n";
}