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
double dp[1111][1111];
int ww,bb;
bool vis[1111][1111];
double dfs(int w,int b)
{
	if(w<=0)return 0;
	if(b<=0)return 1;
	if(vis[w][b]){return dp[w][b];}
	vis[w][b]=1;
	double &d=dp[w][b];
	d=w*1.0/(b+w);
	if(b>1)
	{
		double t=b*1.0/(b+w);b--;
		t*=b*1.0/(b+w);b--;
		t*=b*1.0/(b+w)*dfs(w,b-1)+w*1.0/(b+w)*dfs(w-1,b);
		d+=t;
	}
	return d;
}	
int main()
{
	cin>>ww>>bb;
	printf("%.10lf",dfs(ww,bb));
// 	system("pause");
	return 0;
}