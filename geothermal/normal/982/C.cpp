#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vi> vvi;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = (ll) 1e18;
const int MX = 100001;

vi tree[MX];
int N;
bool visited[MX];
int subs[MX];
int total = -1;

void dfs(int cur) {
	visited[cur] = true;
	int best = 1;
	for (int i : tree[cur]) {
		if (!visited[i]) {
			dfs(i);
			best += subs[i];
		}
	}
	subs[cur] = best;
	total += (best + 1) % 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(subs, 0, sizeof(subs));
	memset(visited, 0, sizeof(visited));

	int N; cin >> N;
	if (N % 2 == 1) {
		cout << -1; return 0;
	}


	F0R(i, N - 1) {
		int a, b; cin >> a >> b; a--; b--;
		tree[a].pb(b); tree[b].pb(a);
	}

	dfs(0);

	cout << total;

	//system("pause");
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)