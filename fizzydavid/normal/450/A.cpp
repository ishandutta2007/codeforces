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
const int INF=1<<28;
int n,m,a[111];
int main()
{
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
	}
	for(int i=n;i>=1;i--)
	{
		if((mx-1)/m+1==(a[i]-1)/m+1)
		{
			cout<<i;
			return 0;
		}
	}
// 	system("pause");
	return 0;
}