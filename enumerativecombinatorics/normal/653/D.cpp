#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}


const int D_MAX_V=202;
const int D_v_size=202;
struct D_wolf{
	int t,c,r;
	D_wolf(){t=c=r=0;}
	D_wolf(int t1,int c1,int r1){
		t=t1;c=c1;r=r1;
	}
};
vector<D_wolf>D_G[D_MAX_V];
int D_level[D_MAX_V];
int D_iter[D_MAX_V];

void add_edge(int from,int to,int cap){
	D_G[from].push_back(D_wolf(to,cap,D_G[to].size()));
	D_G[to].push_back(D_wolf(from,0,D_G[from].size()-1));
}
void D_bfs(int s){
	for(int i=0;i<D_v_size;i++)D_level[i]=-1;
	queue<int> Q;
	D_level[s]=0;
	Q.push(s);
	while(Q.size()){
		int v=Q.front();
		Q.pop();
		for(int i=0;i<D_G[v].size();i++){
			if(D_G[v][i].c>0&&D_level[D_G[v][i].t]<0){
				D_level[D_G[v][i].t]=D_level[v]+1;
				Q.push(D_G[v][i].t);
			}
		}
	}
}
int D_dfs(int v,int t,int f){
	if(v==t)return f;
	for(;D_iter[v]<D_G[v].size();D_iter[v]++){
		int i=D_iter[v];
		if(D_G[v][i].c>0&&D_level[v]<D_level[D_G[v][i].t]){
			int d=D_dfs(D_G[v][i].t,t,min(f,D_G[v][i].c));
			if(d>0){
				D_G[v][i].c-=d;
				D_G[D_G[v][i].t][D_G[v][i].r].c+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		D_bfs(s);
		if(D_level[t]<0)return flow;
		for(int i=0;i<D_v_size;i++)D_iter[i]=0;
		int f;
		while((f=D_dfs(s,t,99999999))>0){flow+=f;}
	}
	return 0;
}
int p[510];
int q[510];
int r[510];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<b;i++){
		scanf("%d%d%d",p+i,q+i,r+i);
		p[i]--;q[i]--;
	}
	double left=0;
	double right=1100000;
	for(int i=0;i<100;i++){
		double M=(left+right)/2;
		for(int j=0;j<a;j++){
			D_level[j]=D_iter[j]=0;
			D_G[j].clear();
		}
		for(int j=0;j<b;j++){
			add_edge(p[j],q[j],(int)min(110000.0,r[j]/M));
		}
		int tmp=max_flow(0,a-1);
		if(tmp>=c){
			left=M;
		}else right=M;
	}
	printf("%.12f\n",right*c);
}