#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s,v1,v2,d1,d2;
int main()
{
	cin>>s>>v1>>v2>>d1>>d2;
	if(s*v1+2*d1<s*v2+2*d2)			cout<<"First\n";
	else if(s*v1+2*d1>s*v2+2*d2)	cout<<"Second\n";
	else							cout<<"Friendship\n";
}