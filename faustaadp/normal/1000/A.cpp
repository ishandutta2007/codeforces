#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,L,B[10][1010],has;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		L=s.length();
		B[L][s[L-1]]++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		L=s.length();
		B[L][s[L-1]]--;
	}
	for(i=1;i<=5;i++)
	{
		has+=abs(B[i]['M']);
		has+=abs(B[i]['S']);
		has+=abs(B[i]['L']);
	}
	has/=2;
	cout<<has<<"\n";
}