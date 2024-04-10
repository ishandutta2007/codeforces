#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 100000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(T a){
	cout << a << '\n';
}
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n,a[1000005];
vector<int>edge[1000005];
int cnt[1000005];
bool ex[1000005];

#define SZ 1000005

int dist[1000005];
int wh[1000005];
queue<P>que;
bool used[1000005];


bool vis[1000005];
int fro[1000005];
int dep[1000005];
vector<int>lst;

int main(){
	g(n);
	bool tw = 0;
	rep(i,n){
		g(a[i]);
		vector<int>num;
		int A = a[i];
		for(int j=2;j*j<=A;j++){
			if(A%j != 0) continue;
			int c = 0;
			while(A%j == 0){
				A /= j;
				c ^= 1;
			}
			if(c){
				num.pb(j);
			}
		}
		if(A != 1) num.pb(A);
		if(num.empty()){
			puts("1"); return 0;
		}
		else if(num.size() == 1){
			if(cnt[num[0]]) tw = 1;
			cnt[num[0]] += 1;
		}
		else{
			edge[num[0]].pb(num[1]);
			edge[num[1]].pb(num[0]);
			
			if(ex[num[0]*num[1]]){
				tw = 1;
			}
			ex[num[0]*num[1]] = 1;
		}
		for(auto at:num) lst.pb(at);
	}
	if(tw){
		puts("2"); return 0;
	}
	int ans = INF;
	SORT(lst); ERASE(lst);
	repn(i,1000){
		if(edge[i].size() <= 1) continue;
		for(auto at:lst){
			vis[at] = 0;
			dep[at] = INF;
			fro[at] = INF;
		}
		queue<int>que;
		rep(j,edge[i].size()) {
		    dep[edge[i][j]] = 0;
		    fro[edge[i][j]] = edge[i][j];
		    que.push(edge[i][j]);
		}
		//cout<<i<<endl;
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(vis[q]) continue;
			if(ans < dep[q]) break;
			vis[q] = 1;
			rep(i,edge[q].size()){
				int to = edge[q][i];
				if(dep[to] > dep[q]+1){
				    dep[to] = dep[q]+1;
				    fro[to] = fro[q];
				}
				if(vis[to]) continue;
				que.push(to);
			}
		}
		for(auto at:lst){
		    if(at == i) continue;
		    rep(j,edge[at].size()){
		        int to = edge[at][j];
		        if(to == i) continue;
		        if(fro[at] != fro[to]){
		            ans = min(ans, 3+dep[at]+dep[to]);
		        }
		    }
		}
	}
	rep(i,SZ){
		if(cnt[i]){
			dist[i] = 0;
			wh[i] = i;
			que.push(mp(i,i));
		}
		else{
			dist[i] = INF;
		}
	}
	while(!que.empty()){
		P p = que.front(); que.pop();
		if(used[p.fi]) continue; used[p.fi] = 1;
		int cs = dist[p.fi];
		int fr = p.sc;
		
		rep(i,edge[p.fi].size()){
			int to = edge[p.fi][i];
			if(dist[to] > cs+1){
				dist[to] = cs+1;
				wh[to] = fr;
			}
			if(!used[to]){
				que.push(mp(to, wh[to]));
			}
		}
	}
	rep(i,SZ){
		rep(j,edge[i].size()){
			if(wh[i] != wh[edge[i][j]]){
				ans = min(ans,dist[i]+dist[edge[i][j]]+3);
			}
		}
	}
	cout << (ans>5e7?-1:ans) << endl;
}