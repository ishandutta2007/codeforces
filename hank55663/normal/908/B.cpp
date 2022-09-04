#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[4]={0,1,2,3};
	char c[55][55];
	pii start;
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		for(int j=0;j<m;j++)
		if(c[i][j]=='S')
		start=mp(i,j);
	}
	char co[105];
	scanf("%s",co);
	int ans=0;
	do{
		pii now=start;
		for(int i=0;co[i]!=0;i++){
			int k=a[co[i]-'0'];
			now.x+=X[k];
			now.y+=Y[k];
			if(now.x<0||now.x>=n||now.y<0||now.y>=m||c[now.x][now.y]=='#')
			break;
			if(c[now.x][now.y]=='E')
			{
				ans++;
				break;
			}
		} 
	}while(next_permutation(a,a+4));
	printf("%d\n",ans);
}