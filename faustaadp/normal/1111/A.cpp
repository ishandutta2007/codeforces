#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s1,s2;
ll i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s1>>s2;
	for(i=0;i<s1.length();i++)s1[i]=(s1[i]=='a'||s1[i]=='i'||s1[i]=='u'||s1[i]=='e'||s1[i]=='o');
	for(i=0;i<s2.length();i++)s2[i]=(s2[i]=='a'||s2[i]=='i'||s2[i]=='u'||s2[i]=='e'||s2[i]=='o');
	if(s1==s2)cout<<"Yes\n";
	else cout<<"No\n";
}