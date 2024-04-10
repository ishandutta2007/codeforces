#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
vector<pair<int,char> > v[105];
int dp[105][105][26];
int DP(int i,int j,int c){
	if(dp[i][j][c]!=-1)
	return dp[i][j][c];
	int ok=0;
	for(auto &it:v[i]){
		if(it.y-'a'>=c){
			if(DP(j,it.x,it.y-'a')==0)
			ok=1;
		}
	}
	return dp[i][j][c]=ok;
}
int main(){
	MEMS(dp);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		char c;
		scanf("%d %d %c",&a,&b,&c);
		v[a].pb(mp(b,c));
	}
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=n;j++){
			if(DP(i,j,0)){
				printf("A");
			}
			else
			printf("B");
		}
}