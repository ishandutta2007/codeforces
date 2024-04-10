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
vector<int> g[MAXN],rg[MAXN],cg[MAXN];
int n,m,belong[MAXN],deg[MAXN];
bool vis[MAXN]; 
vector<int> have[MAXN];
bool query(int A,int B){
	printf("? %d %d\n",A,B);
	ff;
	bool x;
	cin>>x;
	return x;
}
stack<int> sta;
void dfs1(int now){
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it])
			dfs1(it);
	}
	sta.push(now);
}
int cnt=0;
void dfs2(int now){
	vis[now]=1;
	belong[now]=cnt;
	for(auto it:rg[now]){
		if(!vis[it])
			dfs2(it);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		rg[v].PB(u);
	}
	rb(i,1,n) if(!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	while(!sta.empty()){
		int now=sta.top();
		sta.pop();
		if(!vis[now]){
			++cnt;
			dfs2(now);
		}
	}
	rb(i,1,n) for(auto it:g[i]) if(belong[it]!=belong[i]) cg[belong[i]].PB(belong[it]);
	rb(i,1,cnt) sort(ALL(cg[i])),cg[i].erase(unique(ALL(cg[i])),cg[i].end());
	rb(i,1,cnt) for(auto it:cg[i]) deg[it]++;
	rb(i,1,n) have[belong[i]].PB(i);
	vector<int> top;
	rb(i,1,cnt) if(deg[i]==0){
		top.PB(have[i].back());
	}
	while(top.size()>1){
		int A=top.back();top.POB();
		int B=top.back();top.POB();
		if(query(A,B)){
			top.PB(A);
			have[belong[B]].POB();
			if(have[belong[B]].empty()){
				for(auto it:cg[belong[B]]){
					deg[it]--;
					if(deg[it]==0){
						top.PB(have[it].back()); 
					}
				}
			}
			else{
				top.PB(have[belong[B]].back());
			}
		}
		else{
			top.PB(B);
			have[belong[A]].POB();
			if(have[belong[A]].empty()){
				for(auto it:cg[belong[A]]){
					deg[it]--;
					if(deg[it]==0){
						top.PB(have[it].back()); 
					}
				}
			}
			else{
				top.PB(have[belong[A]].back());
			}
		}
	}
	printf("! %d\n",top[0]);
	return 0;
}