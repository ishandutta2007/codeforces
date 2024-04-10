/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+233;
LL dist[MAXN][2][51];
vector<mp> g[MAXN];
int n,m; 
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].PB(II(v,w));
		g[v].PB(II(u,w));
	}
	memset(dist,127,sizeof(dist));
	LL inf=dist[0][0][0]; 
	dist[1][0][0]=0;
	priority_queue<pair<LL,pair<int,mp> > ,vector<pair<LL,pair<int,mp> > >,greater<pair<LL,pair<int,mp> > > > heap;
	heap.push(II(0,II(1,II(0,0))));
	while(!heap.empty()){
		pair<LL,pair<int,mp> > now=heap.top();heap.pop();
		LL val=now.FIR;
		int i,j,k;
		i=now.SEC.FIR,j=now.SEC.SEC.FIR,k=now.SEC.SEC.SEC;
		if(val!=dist[i][j][k]) continue;
		for(auto it:g[i]){
			int w=it.SEC;
			if(j){
				if(val+w*w+2*w*k<dist[it.FIR][0][0]){
					dist[it.FIR][0][0]=val+w*w+2*w*k;
					heap.push(II(val+w*w+2*w*k,II(it.FIR,II(0,0))));
				}
			}
			else{
				if(val+w*w<dist[it.FIR][1][w]){
					dist[it.FIR][1][w]=val+w*w;
					heap.push(II(val+w*w,II(it.FIR,II(1,w))));
				}
			}
		}
	}
	rb(i,1,n){
		if(dist[i][0][0]==inf) dist[i][0][0]=-1;
		printf("%lld ",dist[i][0][0]);
	}
	return 0;
}