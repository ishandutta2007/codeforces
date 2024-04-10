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
int cnt1[30],cnt2[30];
string s,t;
int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)cnt1[s[i]-'a']++;
	for(int i=0;i<t.size();i++)cnt2[t[i]-'a']++;
	int flag=1;
	for(int i=0;i<26;i++)
	{
		if(cnt1[i]<cnt2[i])
		{
			flag=0;
			break;
		}
		if(cnt1[i]>cnt2[i])
		{
			flag=2;
		}
	}
	int f2=1;
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==t[p])p++;
		if(p==t.size())break;
	}
	if(p==t.size())f2=0;
	if(flag==0)
	{
		puts("need tree");
	}
	else if(f2==1&&flag==2)
	{
		puts("both");
	}
	else if(f2==0&&flag==2)
	{
		puts("automaton");
	}
	else if(f2==1&&flag==1)
	{
		puts("array");
	}
// 	system("pause");
	return 0;
}