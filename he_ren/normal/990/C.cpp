#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 3e5 + 5;
const int MAXL = 3e5 + 5;

string s[MAXN];
int t[MAXL];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>s[i];
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		int cl=0, cr=0;
		for(uint j=0; j<s[i].size(); ++j)
		{
			if(s[i][j]=='(') ++cl;
			else
			{
				if(cl) --cl;
				else ++cr;
			}
		}
		
		if(cl && cr) continue;
		
		if(!cr) ++t[cl];
		if(!cl) ans += t[cr];
	}
	
	memset(t,0,sizeof(t));
	for(int i=n; i>=1; --i)
	{
		int cl=0, cr=0;
		for(uint j=0; j<s[i].size(); ++j)
		{
			if(s[i][j]=='(') ++cl;
			else
			{
				if(cl) --cl;
				else ++cr;
			}
		}
		
		if(cl && cr) continue;
		
		if(!cl) ans += t[cr];
		if(!cr) ++t[cl];
	}
	cout<<ans;
	return 0;
}