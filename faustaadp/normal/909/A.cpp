#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s1,s2,s;
ll i;
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>s2;
	s=s1[0];
	for(i=1;i<s1.length();i++)
	{
		if(s1[i]<s2[0])
			s+=s1[i];
		else
			break;
	}
	s=s+s2[0];
	cout<<s<<"\n";
}