#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   cin>> test_num;
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 3e5 + 5, inf = INT_MAX / 2ll;

int n, m; 
int arr[maxn]; 
vector<int> alv;
int num; 
vector<int> g[maxn];  
int occ[maxn]; 
vi byocc[maxn]; 
int banned[maxn]; 
vi diff_occ; 
void solve() {
	cin >> n >> m; 
	//
		alv.clear();
		num = 0; 
		fori(i, 1, n) g[i].clear(); 
		fori(i, 1, n) occ[i] = 0; 
		fori(i, 1, n) byocc[i].clear(); 
		fori(i, 1, n) banned[i] = 0; 
		diff_occ.clear(); 
	//
	fori(i, 1, n) cin >> arr[i]; 
	fori(i, 1, n) alv.eb(arr[i]); 
	sort(b_e(alv)); 
	alv.erase(unique(b_e(alv)), end(alv));
	num = alv.size(); 
	auto get_c = [] (int v) ->int { return lower_bound(b_e(alv), v) - begin(alv) + 1; }; 
	fori(i, 1, n) arr[i] = get_c(arr[i]); 
	fori(i, 1, m) { 
		int u, v; cin >> u  >> v; 
		u = get_c(u); v = get_c(v); 
		g[u].eb(v); 
		g[v].eb(u); 
	}
	fori(i, 1, num) g[i].eb(i);
	fori(i, 1, n) { 
		occ[arr[i]]++; 
	}
	fori(i,1, num) byocc[occ[i]].eb(i); 
	fori(i, 1, n) { 
		if(!byocc[i].empty()) { 
			diff_occ.eb(i); 
			sort(b_e(byocc[i]), [] (int x, int y) -> int { return alv[x] > alv[y]; }); 
		}
	}
	int ans = 0; 
	fori(i, 1, num) { 
		for(int j: g[i]) banned[j] = 1; 
		for(int t: diff_occ) { 	
			for(int j: byocc[t]) { 
				if(!banned[j]) { 
					ans = max(ans, (alv[i - 1] + alv[j - 1]) * (occ[i] + occ[j])); 
					break; 
				}
			}
		}
		for(int j: g[i]) banned[j] = 0; 
	}
	cout << ans << endl; 
}