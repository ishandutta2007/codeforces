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
int n,m,p[2000];
__int64 res=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		while(p[x]!=x)x=p[x];
		while(p[y]!=y)y=p[y];
		if(x!=y)res*=2;
		p[y]=x;
	}
	cout<<res;
// 	system("pause");
	return 0;
}