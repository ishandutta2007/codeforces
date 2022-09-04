#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
//#define pi 3.14159265359
#define rank Rank
using namespace std;
typedef long long LL;
int mod=1e9+7;
int x[8]={-1,-1,-1,0,1,1,1,0};
int y[8]={-1,0,1,1,1,0,-1,-1};
char c[15][15];
int dfs(int a,int b,int d){
	if(c[a][b]!='X')
	return 0;
	else
	return dfs(a+x[d],b+y[d],d)+1;
}
int main()
{	
	for(int i=1;i<=10;i++){
		scanf("%s",c[i]+1);
	}
	int ok=0;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++){
			if(c[i][j]=='.')
			{
				for(int k=0;k<4;k++)
				if(dfs(i+x[k],j+y[k],k)+dfs(i+x[k+4],j+y[k+4],k+4)>=4)
				ok=1;
			}
		}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}