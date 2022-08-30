//Let's join Kaede Takagaki Fun Club !!
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
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n, a[3][100005];
vector<int>za;
int pre[3][300005];
P need[100005];

#define sz (1<<17)

struct up1{
	int seg[sz<<1], segmn[sz<<1];
	int mn[sz<<1], lazy[sz<<1];
	void update(int pos,int v){
		pos += sz-1; mn[pos] = v;
		while(pos){
			pos = (pos-1)/2;
			mn[pos] = min(mn[pos*2+1], mn[pos*2+2]);
		}
	}
	void lazy_evaluate(int k)
	{
		if(k*2+2>=sz*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		mn[k*2+2]+=lazy[k];
		mn[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	void add(int a,int b,int k,int l,int r,int v){
		if(r < a || b < l || a > b || segmn[k] >= v) return;
		if(a <= l && r <= b && seg[k] != -1){
			if(seg[k] < v){
				mn[k] += v-seg[k];
				lazy[k] += v-seg[k];
				seg[k] = v;
			}
			segmn[k] = v;
			return;
		}
		if(seg[k] != -1){
			chmax(seg[k*2+1], seg[k]);
			chmax(seg[k*2+2], seg[k]);
			chmax(segmn[k*2+1], seg[k]);
			chmax(segmn[k*2+2], seg[k]);
		}
		if(lazy[k]) lazy_evaluate(k);
		
		add(a, b, k*2+1, l, (l+r)/2, v);
		add(a, b, k*2+2, (l+r)/2+1, r, v);
		
		if(seg[k*2+1] >= 0 && seg[k*2+2] >= 0 && seg[k*2+1] == seg[k*2+2]){
			seg[k] = seg[k*2+1];
		}
		else seg[k] = -1;
		segmn[k] = min(segmn[k*2+1], segmn[k*2+2]);
		mn[k] = min(mn[k*2+1], mn[k*2+2]);
	}
	int query(){
		return mn[0];
	}
}kaede;


int main(){
	scanf("%d",&n);
	rep(j,3) repn(i,n){
		scanf("%d",&a[j][i]);
		za.pb(a[j][i]);
	}
	
	SORT(za); ERASE(za);
	rep(i,3) rep(j,za.size()) pre[i][j] = INF;
	rep(j,3)repn(i,n){
		int x = POSL(za, a[j][i]);
		chmin(pre[j][x], i);
	}
	for(int i=0;i<=n;i++) kaede.update(i, i);
	for(int i=n+1;i<sz;i++) kaede.update(i, INF);
	kaede.add(n+1, sz-1, 0, 0, sz-1, INF);
	rep(i,za.size()){
		if(pre[0][i] != INF) continue;
		{
			int p = pre[1][i];
			int q = pre[2][i];
			if(p == INF && q == INF){
				kaede.add(0, sz-1, 0, 0, sz-1, INF);
			}
			else if(p == INF){
				kaede.add(0, sz-1, 0, 0, sz-1, q);
			}
			else if(q == INF){
				kaede.add(0, p-1, 0, 0, sz-1, INF);
			}
			else kaede.add(0, p-1, 0, 0, sz-1, q);
		}
	}
	repn(i,n){
		int x = POSL(za, a[0][i]);
		need[i] = mp(-1, -1);
		if(pre[0][x] == i){
			int p = pre[1][x];
			int q = pre[2][x];
			if(p == INF && q == INF){
				need[i] = mp(sz-1, INF);
			}
			else if(p == INF){
				need[i] = mp(sz-1, q);
			}
			else if(q == INF){
				need[i] = mp(p-1, INF);
			}
			else need[i] = mp(p-1, q);
		}
	}
	int ans = INF;
	chmin(ans, n + kaede.query());
	for(int i=n;i>=1;i--){
		int cur = i-1;
		if(need[i].fi == INF) break;
		kaede.add(0, need[i].fi, 0, 0, sz-1, need[i].sc);
		chmin(ans, cur + kaede.query());
		if(kaede.query() >= ans) break;
	}
	cout << ans << endl;
}