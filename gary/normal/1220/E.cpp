//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL res=0;
int w[200000+10],col[200000+10],v[200000+10];
vector<int> each[200000+10];
int n,m;
bool dfs(int now,int prev){
	if(v[now]){
		col[now]=1;
		return 1;
	}
	v[now]=1;
	int OK=0;
	for(auto it:each[now]){
		if(it!=prev)
		OK|=dfs(it,now);
	}
//	v[now]=0;
	if(OK) col[now]=1;
	return OK;
}
LL add=0;
void dfs2(int now,LL val,int prev){
	if(v[now]) return;
	v[now]=1;
	if(col[now]){
		for(auto it:each[now]){
			if(it!=prev)
			dfs2(it,val,now);
		}
	}
	else{
		add=max(add,val+w[now]);
		for(auto it:each[now]){
			if(it!=prev)
			dfs2(it,val+w[now],now);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	rb(i,1,n) scanf("%d",&w[i]);
	rb(i,1,m){
		int u,v;
		scanf("%d %d",&u,&v);
		each[u].PB(v);
		each[v].PB(u);
	}
	int s;
	cin>>s;
	dfs(s,-1);
	rb(i,1,n){
		if(col[i]) res+=w[i];
//		cout<<i<<endl;
	}
	memset(v,0,sizeof(v));
	dfs2(s,0,-1);
//	cout<<res<<endl;
	res+=add;
	cout<<res<<endl;
	return 0;
}