#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char c[200][200];
	for(int i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	pii lef=mp(1e9,1e9),right=mp(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]=='B'){
				lef=min(lef,mp(i,j));
				right=max(right,mp(i,j));
			}
		}
	}
//	printf("%d %d %d %d\n")
	printf("%d %d\n",(lef.x+right.x)/2,(lef.y+right.y)/2);
}