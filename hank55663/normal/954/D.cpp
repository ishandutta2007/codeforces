#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int dis[1005][1005];
vector<int> v[1005];
int main(){
	MEMS(dis);
	int n,m,s,t;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		queue<int> q;
		q.push(i);
		dis[i][i]=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(auto it:v[x]){
				if(dis[i][it]==-1){
					dis[i][it]=dis[i][x]+1;
					q.push(it);
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]!=1){
				if(dis[s][i]+dis[j][t]+1>=dis[s][t]&&dis[s][j]+dis[i][t]+1>=dis[s][t])
					cnt++;
			}
		}
	printf("%d\n",cnt);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/