//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int a[100005],b[100005];
bool ok[100005][2]={};
int all[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		all[i*2]=a[i]; all[i*2+1]=b[i];
	}
	sort(all,all+2*n);
	int v=all[n-1];
	for(int i=0;i<n;i++)
	{
		if(v>=a[i]) ok[i][0]=true;
		if(v>=b[i]) ok[i][1]=true;
	}
	for(int i=0;2*(i+1)<=n;i++)
	{
			ok[i][0]=true;
			ok[i][1]=true;
	}
	for(int i=0;i<2;i++)
	{
			for(int j=0;j<n;j++)
			{
					printf("%d",ok[j][i]);
			}
			puts("");
	}
	cin >> n;
}