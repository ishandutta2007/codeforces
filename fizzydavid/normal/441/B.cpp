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
#define cal(x) max(0,x)
int d[3111],n,v,mx;
int main()
{
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]+=y;mx=max(mx,x);
	}
	int res=min(d[1],v);
	d[1]=cal(d[1]-v);
	for(int i=2;i<=mx+1;i++)
	{
		res+=min(d[i]+d[i-1],v);
		if(d[i-1]<v)d[i]=cal(d[i]+d[i-1]-v);
	}
	cout<<res;
// 	system("pause");
	return 0;
}