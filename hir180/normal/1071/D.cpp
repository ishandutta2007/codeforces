#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
map<vector<int>,int>M;
int dv[2505];
int nxt;
vector<int>vec;
int p[15]={2,3,5,7,11,13,17,19,23,29,31,37};
void dfs(ll num,int last,int nxtt,int mul){
	if(num > 10000000000) return;
	if(M.find(vec) == M.end()){
		dv[nxt] = mul;
		M[vec] = nxt++;
	}
	for(int i=1;i<=last;i++){
		num *= p[nxtt];
		if(num > 10000000000) return;
		vec.pb(i);
		dfs(num,i,nxtt+1,mul*(i+1));
		vec.pop_back();
	}
}
int dist[2505][2505];
int D[2505][2505];
bool used[2505][2505];
vector<int>edge[2505];
int t;
int go[1000005];
int main(){
	dfs(1,31,0,1); 
	for(map<vector<int>,int>::iterator it=M.begin();it!=M.end();++it){
		vector<int>vec = it->fi;
		int id = it->sc;
		for(int i=0;i<=vec.size();i++){
			vector<int>vec2;
			rep(j,vec.size()) vec2.pb(vec[j]+(i==j));
			if(i == vec.size()) vec2.pb(1);
			sort(vec2.begin(),vec2.end(),greater<int>());
			if(M.find(vec2) != M.end()){
				edge[id].pb(M[vec2]);
			}
			if(i == vec.size()) break;
			vec2.clear();
			rep(j,vec.size()) vec2.pb(vec[j]-(i==j));
			sort(vec2.begin(),vec2.end(),greater<int>());
			while(vec2[vec2.size()-1] == 0) vec2.pop_back();
			if(M.find(vec2) != M.end()){
				edge[id].pb(M[vec2]);
			}
		}
	}
	rep(a,2505)rep(b,2505) dist[a][b] = D[a][b] = INF;
	for(int i=0;i<nxt;i++){
		dist[i][i] = 0;
		queue<int>que;
		que.push(i);
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(used[i][q]) continue;
			used[i][q] = 1;
			for(int ii=0;ii<edge[q].size();ii++){
				int to = edge[q][ii];
				dist[i][to] = min(dist[i][to],dist[i][q]+1);
				if(!used[i][to]){
					que.push(to);
				}
			}
		}
		for(int j=0;j<nxt;j++){
			D[i][dv[j]] = min(D[i][dv[j]],dist[i][j]);
		}
	}
	for(int i=2;i<=1000000;i++){
		if(go[i]) continue;
		for(int j=2;i*j<=1000000;j++){
			go[i*j] = i;
		}
	}
	scanf("%d",&t);
	for(int ii=0;ii<t;ii++){
		int a,b; scanf("%d%d",&a,&b);
		map<int,int>A,B;
		while(a>1){
			if(go[a] == 0) {A[a]++; break;}
			A[go[a]]++;
			a /= go[a];
		}
		while(b>1){
			if(go[b] == 0) {B[b]++; break;}
			B[go[b]]++;
			b /= go[b];
		}
		vector<int>va,vb;
		for(map<int,int>::iterator it=A.begin();it!=A.end();it++){
			va.pb(it->sc);
		}
		for(map<int,int>::iterator it=B.begin();it!=B.end();it++){
			vb.pb(it->sc);
		}
		sort(va.begin(),va.end(),greater<int>());
		sort(vb.begin(),vb.end(),greater<int>());
		int xa = M[va];
		int xb = M[vb];
		int ans = INF;
		for(int i=0;i<2505;i++) {ans = min(ans,D[xa][i]+D[xb][i]);}
		printf("%d\n",ans);
	}
}