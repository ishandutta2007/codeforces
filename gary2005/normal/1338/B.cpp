/**
 *    author:  gary
 *    created: 01.09.2021
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+1;
vector<int> g[MAXN];
int n;
bool ok=1;
int P=-1;
bool leaf[MAXN];
void dfs(int now,int pre,int depth=0){
	for(auto it:g[now]) if(it!=pre) dfs(it,now,depth^1);
	if(pre!=0&&g[now].size()==1){
		if(P==-1) P=depth;
		if(P!=depth) ok=0;
		leaf[now]=1;
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	int root=0;
	rb(i,1,n) if(g[i].size()>1) root=i;
	dfs(root,0);
	if(ok) cout<<"1 ";
	else cout<<"3 ";
	int cnt=n-1;
	rb(i,1,n) if(!leaf[i]){
		int c=0;
		for(auto it:g[i]){
			c+=leaf[it];
		}
		cnt-=max(0,c-1);
	} 
	cout<<cnt<<endl;
	return 0;
}