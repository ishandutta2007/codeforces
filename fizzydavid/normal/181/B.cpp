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
int n,x[3111],y[3111];
bool vis[2111][2111];
int main()
{
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		vis[x[i]+1000][y[i]+1000]=1;
		x[i]+=1000;
		y[i]+=1000;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((x[i]+x[j])%2==0&&(y[i]+y[j])%2==0&&vis[(x[i]+x[j])/2][(y[i]+y[j])/2])cnt++;
		}
	}
	cout<<cnt;
		
// 	system("pause");
	return 0;
}