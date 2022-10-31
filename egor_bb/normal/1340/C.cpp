#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
const int M = 1e4 + 100;
const int N = 1e6 + 100;
const int T = 1005;
const ll INF = 1e18;
 
ll dist[M][T];
bool used[M][T];
int x[M];
vector<pii> q[N];
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		cin >> x[i];
	}
        sort(x, x+m);
	int g, r;
	cin >> g >> r;
	forn(i, m) {
		forn(j, g) {
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
	q[0].pb(mp(0, 0));
	set<int> nextPos;
	nextPos.insert(0);
	ll ans = INF;
	while(!nextPos.empty()) {
		int curDist = *nextPos.begin();
		nextPos.erase(nextPos.begin());
		int vInd = curDist % N;
		
		while(!q[vInd].empty()) {
			int pos = q[vInd].back().fst;
			int mod = q[vInd].back().snd;
			q[vInd].pop_back();
			
		//	cout << pos << " " << mod << '\n';
			if (used[pos][mod]) {
				continue;
			}
			used[pos][mod] = 1;
 
			ll curD = dist[pos][mod];
			
			if (pos - 1 >= 0) {
				int d = x[pos] - x[pos - 1];
				int nextStep = mod + x[pos] - x[pos - 1];
				if (nextStep <= g) {
					if (nextStep == g) {
						nextStep = 0;
						d += r;
					}
					if (curD + d < dist[pos - 1][nextStep]) {
						dist[pos - 1][nextStep] = curD + d;
						int ind = (curD + d) % N;
						if (q[ind].empty()) nextPos.insert(ind);
						q[ind].pb(mp(pos - 1, nextStep));
					}
				}
			}
			if (pos + 1 < m) {
//				cout << "!";
				int d = x[pos + 1] - x[pos];
				int dReal = x[pos + 1] - x[pos];
				int nextStep = mod + x[pos + 1] - x[pos];
				if (nextStep <= g) {
					if (nextStep == g) {
						nextStep = 0;
						d += r;
					}
					if (curD + d < dist[pos + 1][nextStep]) {
						dist[pos + 1][nextStep] = curD + d;
						if (pos + 1 == m - 1) {
							ans = min(ans, curD + dReal);
						}
						int ind = (curD + d) % N;
			//			cout << ind << '\n';
						if (q[ind].empty()) nextPos.insert(ind);
						q[ind].pb(mp(pos + 1, nextStep));
					}
				}
			}
		}
	}
 
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
	
    return 0;
}