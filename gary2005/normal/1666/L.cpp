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
const int MAXN=2e5+10;
int n,m,s;
vector<int> g[MAXN];
int pre[MAXN],col[MAXN];
void print(int t,int x,int y){
	cout<<"Possible\n";
	vector<int> p1,p2;
	p1.PB(t),p2.PB(t);
	while(true){
		p1.PB(x);
		if(x==s) break;
		x=pre[x];
	}
	while(true){
		p2.PB(y);
		if(y==s) break;
		y=pre[y];
	}
	reverse(ALL(p1));
	reverse(ALL(p2));
	cout<<p1.size()<<endl;
	for(auto it:p1) cout<<it<<" ";
	cout<<endl;
	cout<<p2.size()<<endl;
	for(auto it:p2) cout<<it<<' ';
	cout<<endl;
	exit(0);
}
void dfs(int now){
	for(auto it:g[now]){
		if(it==s) continue;
		if(!col[it]){
			col[it]=col[now];
			pre[it]=now;
			dfs(it);
		}
		else{
			if(col[it]!=col[now]){
				print(it,now,pre[it]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
	}
	for(auto it:g[s]){
		if(col[it]){
			print(it,pre[it],s);
		}
		col[it]=it;
		pre[it]=s;
		dfs(it);
	}
	cout<<"Impossible\n";
    return 0;
}