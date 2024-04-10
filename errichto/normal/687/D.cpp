#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int N = 1005;
const int pot = 512 * 1024;

int g[N], kind[N];
vi inv[N];
int kol[2 * 1000 * 1000 + 123456];

vi merge(vi & one, vi & two) {
	vi ans = vi{-1};
	if(!one.empty()) ans[0] = one[0];
	if(!two.empty()) maxi(ans[0], two[0]);
	int i_one = 1, i_two = 1;
	int i_kol = 0;
	while(i_one < sz(one) || i_two < sz(two)) {
		int a, b, c;
		if(i_two >= sz(two) || (i_one < sz(one) && one[i_one+2] > two[i_two+2])) {
			a = one[i_one];
			b = one[i_one + 1];
			c = one[i_one + 2];
			i_one += 3;
		}
		else {
			a = two[i_two];
			b = two[i_two + 1];
			c = two[i_two + 2];
			i_two += 3;
		}
		kol[i_kol++] = a;
		kol[i_kol++] = b;
		if(g[a] == g[b]) {
			if(kind[a] != kind[b]) continue;
			else {
				maxi(ans[0], c);
				break;
			}
		}
		bool przeklam = (kind[a] == kind[b]);
		ans.pb(a);
		ans.pb(b);
		ans.pb(c);
		a = g[a];
		b = g[b];
		if(inv[a].size() > inv[b].size()) swap(a, b);
		for(int x : inv[a]) {
			inv[b].pb(x);
			g[x] = b;
			if(przeklam) kind[x] ^= 1;
		}
		inv[a].clear();
	}
	REP(i, i_kol) {
		int x = kol[i];
		inv[x] = vi{x};
		g[x] = x;
		kind[x] = 0;
	}
	return ans;
}

vi tr[2*pot];

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	RI(i, n) {
		g[i] = i;
		inv[i] = vi{i};
	}
	RI(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tr[pot+i] = vi{-1,a,b,c};
	}
	FORD(i, pot - 1, 1) tr[i] = merge(tr[2*i], tr[2*i+1]);
	//for(int x : tr[pot / 4]) printf("%d ", x);
	//puts("");
	while(q--) {
		int low, high;
		scanf("%d%d", &low, &high);
		low += pot;
		high += pot;
		vi ans = tr[low];
		if(low != high) ans = merge(ans, tr[high]);
		while(low < high - 1) {
			if(low % 2 == 0) ans = merge(ans, tr[low+1]);
			if(high % 2 == 1) ans = merge(ans, tr[high-1]);
			low /= 2;
			high /= 2;
		}
		printf("%d\n", ans[0]);
	}
	return 0;
}