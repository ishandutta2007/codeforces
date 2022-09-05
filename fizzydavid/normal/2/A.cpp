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
int n;
map<string,int> m;
pair<string,int> p[1111];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;int d;
		cin>>s>>d;
		m[s]+=d;
		p[i].ff=s;
		p[i].ss=m[s];
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,m[p[i].ff]);
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].ss>=mx&&m[p[i].ff]==mx)
		{
			cout<<p[i].ff;
			//system("pause");
			return 0;
		}
	}
 	
	return 0;
}