#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1e5 + 7; vector < int > nxt[_]; int N , Q , A[_];
int dfn[_] , sz[_] , son[_] , top[_] , fa[_] , dep[_] , ts;
void dfs1(int x , int p){
	fa[x] = p; dep[x] = dep[p] + 1; sz[x] = 1;
	for(auto t : nxt[x]) if(t != p){dfs1(t , x); sz[x] += sz[t]; son[x] = sz[son[x]] < sz[t] ? t : son[x];}
}
void dfs2(int x , int t){
	dfn[x] = ++ts; top[x] = t; if(!son[x]) return;
	dfs2(son[x] , t); for(auto p : nxt[x]) if(p != son[x] && p != fa[x]) dfs2(p , p);
}

int qsum(int x , int y){return max(abs(x + y) , abs(x - y));}
struct dat{int lv , rv , sum;}tr[_ << 2];
dat merge(dat p , dat q){
	dat r; r.lv = p.lv; r.rv = q.rv; r.sum = p.sum + q.sum + qsum(p.rv , q.lv); return r;
}
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void up(int x){tr[x] = merge(tr[lch] , tr[rch]);}
void mdf(int x , int l , int r , int t , int v){
	if(l == r){tr[x].lv = tr[x].rv = v; tr[x].sum = 0; return;}
	if(mid >= t) mdf(lch , l , mid , t , v); else mdf(rch , mid + 1 , r , t , v);
	up(x);
}
dat qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	if(mid < L) return qry(rch , mid + 1 , r , L , R);
	if(mid >= R) return qry(lch , l , mid , L , R);
	return merge(qry(lch , l , mid , L , R) , qry(rch , mid + 1 , r , L , R));
}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> Q; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 1 ; i < N ; ++i){int s , t; cin >> s >> t; nxt[s].push_back(t); nxt[t].push_back(s);}
	dfs1(1 , 0); dfs2(1 , 1); for(int i = 1 ; i <= N ; ++i) mdf(1 , 1 , N , dfn[i] , A[i]);
	while(Q--){
		int id , u , x; cin >> id >> u >> x;
		if(id == 1){A[u] = x; mdf(1 , 1 , N , dfn[u] , x);}
		else{
			int sum = 0;
			while(top[u] != top[x]){
				if(dep[top[u]] < dep[top[x]]) swap(u , x);
				sum += qry(1 , 1 , N , dfn[top[u]] , dfn[u]).sum + qsum(A[top[u]] , A[fa[top[u]]]);
				u = fa[top[u]];
			}
			if(dep[u] > dep[x]) swap(u , x);
			sum += qry(1 , 1 , N , dfn[u] , dfn[x]).sum;
			cout << sum << endl;
		}
	}
	return 0;
}