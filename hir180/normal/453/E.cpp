#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
#define fi first
#define sc second
#define mp make_pair
const int INF = 1000000007;
int n, s[100005], q;
const int sz = (1<<17);
struct sg{
	vector<P1>seg[(1<<18)];
	vector<ll>slope[(1<<18)], maxv[(1<<18)];
	int las[(1<<18)];
	
	void set(int pos, P1 p){
		pos += sz-1;
		seg[pos].pb(p);
		slope[pos].pb(p.sc.sc);
		maxv[pos].pb(p.sc.fi);
	}
	void make(){
		memset(las, -1, sizeof(las));
		for(int i=sz-2;i>=0;i--){
			seg[i].resize(seg[i*2+1].size() + seg[i*2+2].size());
			merge(seg[i*2+1].begin(), seg[i*2+1].end(), seg[i*2+2].begin(), seg[i*2+2].end(), seg[i].begin());
			ll s = 0, m = 0;
			rep(j, seg[i].size()){
				s += seg[i][j].sc.sc;
				m += seg[i][j].sc.fi;
				slope[i].pb(s); maxv[i].pb(m);
			}
		}
	}
	ll query(int a, int b, int k, int l, int r, int t){
		if(r < a || b < l || a > b) return 0LL;
		if(a <= l && r <= b){
			if(las[k] != -1){
				int dif = t - las[k]; las[k] = t;
				int x = lower_bound(seg[k].begin(), seg[k].end(), mp(dif, mp(-1, -1))) - seg[k].begin();
				ll ret = 0;
				//[0, x) -> max
				//[x, sz) -> slope
				if(x > 0) ret += maxv[k][x-1];
				ret += 1LL * (slope[k].back() - (x?slope[k][x-1]:0LL)) * dif;
				return ret;
			}
			else if(l == r){
				las[k] = t;
				return min(1LL*maxv[k].back(), 1LL*s[l]+1LL*slope[k].back()*t);
			}
		}
		propagate(k);
		ll ret = 0;
		ret += query(a, b, k*2+1, l, (l+r)/2, t);
		ret += query(a, b, k*2+2, (l+r)/2+1, r, t);
		if(las[k*2+1] != -1 && las[k*2+1] == las[k*2+2]) las[k] = las[k*2+1];
		else las[k] = -1;
		return ret;
	}
	void propagate(int k){
	    if(las[k] != -1 && las[k*2+1] != -1) las[k*2+1] = max(las[k*2+1], las[k]);
	    if(las[k] != -1 && las[k*2+2] != -1) las[k*2+2] = max(las[k*2+2], las[k]);
	}
}kaede;


int main(){
	scanf("%d", &n);
	repn(i, n){
		int m, r;
		scanf("%d%d%d", &s[i], &m, &r);
		int x = (r ? m/r : INF);
		kaede.set(i, mp(x, mp(m, r)));
	}
	kaede.make();

	scanf("%d", &q);
	rep(i, q){
		int t, a, b; scanf("%d%d%d", &t, &a, &b);
		printf("%lld\n", kaede.query(a, b, 0, 0, sz-1, t));
	}
}