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
const int MAXN=1e6;
vector<int> g[MAXN+2];
bool vis[MAXN+2];
vector<int> rest;
stack<int> sta;
void dfs(int now){
	vis[now]=1;
	sta.push(now);
	for(auto it:g[now]){
		if(vis[it]){
			while(true){
				int now=sta.top();sta.pop();
				rest.PB(now);
				if(now==it) break;
			}
			return ;
		}
		else{
			dfs(it);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	int n;
	scanf("%d",&n);
	rb(i,1,n) vis[i]=0,g[i].clear();
	rest.clear();
	while(!sta.empty()) sta.pop();
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		ai=i-ai;
		g[i].PB(ai);
	}
	dfs(1);
	printf("%d\n",(int)rest.size());
	for(auto it:rest){
		printf("%d ",it);
	}
	puts("");}
	return 0;
}