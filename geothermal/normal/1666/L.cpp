#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, v) for (auto &a : v)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	int S; cin >> S; S--;
	vector<vi> graph(N);
	vi sr;
	F0R(i, M) {
		int X, Y; cin >> X >> Y; X--; Y--;
		if (Y == S) continue;
		if (X == S) {
			sr.pb(Y);
		} else {
			graph[X].pb(Y); 
		}
	}

	int p[N]; F0R(i, N) p[i] = -1;
	int lst[N];
	trav(r, sr) {
		if (p[r] != -1) {
			cout << "Possible" << nl;
			cout << 2 << nl;
			cout << S +1 << " " << r+1 << nl;
			vi cp;
			cp.pb(r);
			while (cp[sz(cp) - 1] != S) {
				cp.pb(lst[cp[sz(cp)-1]]);
			}
			cout << sz(cp) << nl;
			reverse(all(cp));
			trav(a, cp) {
				cout << a+1 << " ";
			}
			cout << nl;
			return 0;
		}
		queue<int> q; q.push(r);
		p[r] = r;
		lst[r] = S;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			trav(a, graph[v]) {
				if (p[a] == -1) {
					lst[a] = v; 
					p[a] = p[v];
					q.push(a);
				} else if (p[a] != p[v]) {
					cout << "Possible" << nl;
					vi p1;
					p1.pb(a);
					p1.pb(v);
					while (p1[sz(p1) - 1] != S) {
						p1.pb(lst[p1[sz(p1)-1]]);
					}
					reverse(all(p1));
					cout << sz(p1) << nl;
					trav(a, p1) {
						cout << a+1 << " ";
					}
					cout << nl;

					vi p2;
					p2.pb(a);
					while (p2[sz(p2) - 1] != S) {
						p2.pb(lst[p2[sz(p2)-1]]);
					}
					reverse(all(p2));
					cout << sz(p2) << nl;
					trav(a, p2) {
						cout << a+1 << " ";
					}
					cout << nl;
					return 0;
				}
			}
		}
	}

	cout << "Impossible" << nl; 
}