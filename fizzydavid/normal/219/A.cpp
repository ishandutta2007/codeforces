#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
string s;
char rp[1111],rpi;
int k,lt[26];
int main()
{
	cin>>k>>s;
	for(int i=0;i<s.size();i++)lt[s[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(lt[i]%k==0)
		{
			for(int r=0;r<lt[i]/k;r++)rp[rpi]='a'+i,rpi++;
		}
		else
		{
			puts("-1");return 0;
		}
	}
	for(int i=0;i<s.size()/rpi;i++)
	{
		for(int j=0;j<rpi;j++)cout<<rp[j];
	}
	return 0;
}