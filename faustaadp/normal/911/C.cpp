#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll a[10];
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+1+3);
	//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"\n";
	if(a[1]==1)
		cout<<"YES\n";
	else
	if(a[1]==2&&a[2]==2)
		cout<<"YES\n";
	else
	if(a[1]==3&&a[2]==3&&a[3]==3)
		cout<<"YES\n";
	else
	if(a[1]==2&&a[2]==4&&a[3]==4)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}