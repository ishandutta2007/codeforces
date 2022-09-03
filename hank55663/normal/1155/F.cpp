#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
short dp[1<<14][15][15][2];
pair<pii,pii> from[1<<14][15][15][2];
short fromz[1<<14][15][15][2]; 
short fromop[1<<14][15][15][2];
vector<int> v[15];
int n;
vector<pii> edge;
int DP(int x,int y,int z,int op){
	if(dp[x][y][z][op]!=-1)return dp[x][y][z][op];
	dp[x][y][z][op]=1e3;
	/*if(x==(1<<0)+(1<<8)+(1<<10)){
		printf("%d %d %d %d\n",x,y,z,op);
		getchar();
	}*/
	if(y!=0)
	{
		for(auto it:v[y]){
			if((1<<(it-1))&x){
				if(mp(it,y)==edge.back()||mp(y,it)==edge.back())continue;
				int value;
				if(it!=z){
					int value= DP(x^(1<<(y-1)),it,z,0);
					if(value+1<dp[x][y][z][op]){
						dp[x][y][z][op]=value+1;
						from[x][y][z][op]=mp(mp(x^(1<<(y-1)),it),mp(y,it));
						fromz[x][y][z][op]=z;
						fromop[x][y][z][op]=0;
					}
				}
				if(op==0||it!=z){
					value = DP(x^(1<<(y-1)),0,0,0);
					if(value+1<dp[x][y][z][op]){
						dp[x][y][z][op]=value+1;
						fromz[x][y][z][op]=0;
						from[x][y][z][op]=mp(mp(x^(1<<(y-1)),0),mp(y,it));
						fromop[x][y][z][op]=0;
					}
				}
			}
		}
	}
	else{
		for(int i = 1;i<=n;i++){
			if((1<<(i-1))&x){
				for(auto it:v[i]){
					if(((1<<(it-1))&x)==0)continue;
					edge.pb(mp(it,i));
					int value =DP(x,i,it,1);
					if(value+1<dp[x][y][z][op]){
						dp[x][y][z][op]=value+1;
						from[x][y][z][op]=mp(mp(x,i),mp(it,i));
						fromz[x][y][z][op]=it;
						fromop[x][y][z][op]=1;
					}
					edge.pop_back();
				}
			}
		}
	}
	return dp[x][y][z][op];
}
int main(){
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);

		v[x].pb(y);
		v[y].pb(x);
	}
	memset(dp,-1,sizeof(dp));
	dp[1][0][0][0]=0;
	printf("%d\n",DP((1<<n)-1,0,0,0));
	vector<pii> v;
	int x=(1<<n)-1,y=0,z=0,op=0;
	while(x!=1||y!=0){
	//	printf("%d %d %d %d\n",x,y,from[x][y][z].y.x,from[x][y][z].y.y);
	//	getchar();
		v.pb(from[x][y][z][op].y);
		pii p = from[x][y][z][op].x;
		int tempz = fromz[x][y][z][op];
		op = fromop[x][y][z][op];
		z=tempz;
		x=p.x;
		y=p.y;
	}
	//assert(v.size()==DP((1<<n)-1,0));
	for(auto it:v)
	printf("%d %d\n",it.x,it.y);
}