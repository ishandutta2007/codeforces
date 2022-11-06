#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll a[1010],n,d1,d2;
char c1,c2;
int main()
{
	cin>>c1>>c2;
	a['^']=0;
	a['>']=1;
	a['v']=2;
	a['<']=3;
	d1=a[c1];
	d2=a[c2];
	cin>>n;
	n=n%4;
	if(n==2||n==0)
		cout<<"undefined\n";
	else
	if(n==1)
	{
		if(d2-d1==1||(d2==0&&d1==3))
			cout<<"cw\n";
		else
		if(d1-d2==1||(d1==0&&d2==3))
			cout<<"ccw\n";
		else
			cout<<"undefined\n";
	}
	else
	if(n==3)
	{
		if(d2-d1==1||(d2==0&&d1==3))
			cout<<"ccw\n";
		else
		if(d1-d2==1||(d1==0&&d2==3))
			cout<<"cw\n";
		else
			cout<<"undefined\n";
	}
}