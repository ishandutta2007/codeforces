#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n;
string s;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		cin>>s;
		if(s.length()<=10)cout<<s<<'\n';
		else
		{
			cout<<s[0]<<s.length()-2<<s[s.length()-1]<<'\n';
		}
	}
	return 0;
}