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
const int MAXN=102;
vector<int> g[MAXN];
vector<int> rg[MAXN];
int a[MAXN],n,m,num[MAXN],ind[MAXN];
LL b[MAXN];
bool vis[MAXN];
LL rest=0;
void gao(int now){
	num[now]=1;
	for(auto it:g[now]) {
		if(!num[it]) gao(it);
		check_max(num[now],num[it]+1);
	}
}
void get(int now){
	vis[now]=1;
	for(auto it:rg[now]){
		if(!vis[it]&&num[it]==num[now]+1){
			get(it);
		}
	}
}
int main(){
//	freopen("dag.in","r",stdin);
//	freopen("dag.out","w",stdout);
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].PB(v);
		rg[v].PB(u);
		a[u]+=w;
		a[v]-=w;
		ind[v]++;
	}
	rb(i,1,n) if(!ind[i]) gao(i);
	LL rest=0;
	rb(i,1,n) rest+=1ll*num[i]*a[i];
	while(true){
		memset(vis,0,sizeof(vis));
		LL Best=1e18;
		vector<int> z;
		rb(F,1,n){
			memset(vis,0,sizeof(vis));
			get(F);
			vector<int> cm;
			LL now=0;
			rb(i,1,n) if(vis[i]) cm.PB(i),now+=a[i];
			if(Best>now){
				Best=now;
				z=cm;
			}
			while(cm.size()!=n){
				int tmp=0;
				rb(i,1,n){
					if(!vis[i]){
						b[i]=0;
						get(i);
						rb(j,1,n) if(vis[j]) b[i]+=a[j];
						if(tmp==0||b[i]<b[tmp]) tmp=i;
						memset(vis,0,sizeof(vis));
						for(auto it:cm){
							vis[it]=1;	
						}
					}
				}
				now=b[tmp];
				get(tmp);
				cm.clear();
				rb(i,1,n) if(vis[i]) cm.PB(i);
				if(Best>now){
					Best=now;
					z=cm;
				}
			}
		}
		if(Best>=0) break;
		rest+=Best;
		for(auto it:z) num[it]++;
	}
	rb(i,1,n) cout<<num[i]<<" ";
	return 0;
}
/*
3 2
2 1 4
1 3 2

5 4
1 2 1
2 3 1
1 3 6
4 5 8


5 5
1 2 1
2 3 1
3 4 1
1 5 1
5 4 10

*/