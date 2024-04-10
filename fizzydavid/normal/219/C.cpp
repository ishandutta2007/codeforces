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
int n,k;
char c[501111],s[501111];
int solve()
{
	int cal=0;
	for(int i=1;i<n;i++)
	{
		if(c[i]==c[i-1])
		{
			if(k<=2)c[i]=(c[i-1]=='A'?'B':'A');
			else
			{
				if(c[i-1]!='C'&&(i==n-1||c[i+1]!='C'))c[i]='C';
				else if(c[i-1]!='B'&&(i==n-1||c[i+1]!='B'))c[i]='B';
				else if(c[i-1]!='A'&&(i==n-1||c[i+1]!='A'))c[i]='A';
			}
			cal++;
		}
	}
	return cal;
}		

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",&s);
	for(int i=0;i<n;i++)c[i]=s[i];
	int res=solve();
	if(k==2)
	{
		for(int i=0;i<n;i++)swap(s[i],c[i]);
		int sol=1;
		c[0]=(c[0]=='A'?'B':'A');
		sol+=solve();
		if(res<sol)cout<<res<<endl<<s;else cout<<sol<<endl<<c;
	}
	else
	{
		cout<<res<<endl<<c;
	}
// 	system("pause");
	return 0;
}