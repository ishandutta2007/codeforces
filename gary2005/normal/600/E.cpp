/*
AuThOr Gwj
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=1e5+10;
int n,c[MAXN];
pair<int,LL > res[MAXN];
vector<int> g[MAXN];
map<int,int> dfs(int now,int pre){
	map<int,int> cnt,tmp;
	cnt[c[now]]=1;
	res[now]=II(1,c[now]);
	for(auto it:g[now]){
		if(it!=pre){
			tmp=dfs(it,now);
			if(cnt.size()<tmp.size()){
				swap(cnt,tmp);
				res[now]=res[it];
			}
			for(map<int,int> :: IT ite=tmp.begin();ite!=tmp.end();ite++){
				cnt[ite->FIR]+=ite->SEC;
				if(cnt[ite->FIR]>res[now].FIR){
					res[now]=II(cnt[ite->FIR],ite->FIR);
				}
				else{
					if(cnt[ite->FIR]==res[now].FIR){
						res[now].SEC+=ite->FIR;
					}
				}
			}
		}
	}
	return cnt;
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n){
		cin>>c[i];
	}
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	
	rb(i,1,n){
		cout<<res[i].SEC<<" ";
	}
	return 0;
}