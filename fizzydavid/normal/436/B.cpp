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
int n,m,k,ans[2111];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		char c[2111];
		scanf("%s",&c);
		for(int j=0;j<m;j++)
		{
			if(c[j]=='U'&&(i%2==0))ans[j]++;
			if(c[j]=='L'&&j-i>=0)ans[j-i]++;
			if(c[j]=='R'&&j+i<m)ans[j+i]++;
		}
	}
	for(int i=0;i<m;i++)printf("%d ",ans[i]);
 //	system("pause");
	return 0;
}