#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define vpii vector<pii>
#define vvpii vector<vpii>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define con continue
#define eb emplace_back
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve()

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
       swap (a, b);
    }
    return a;
}

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ct(vpii &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(vvpii &a) {
    for (auto &i: a) ct(i);
}

void ct(vector<vector<int>> &a) {
    for(auto &i: a) ct(i);
}

void ct(vector<set<int>> &a) {
    for(auto &i: a) {
        for(auto &j: i) cout << j << ' ';
        cout << '\n';
    }
}

void ct(set<int> &a) {
    for(auto i: a) cout << i << ' ';
    cout << '\n';
}

void ct(set<pii> &a) {
    for(auto &i: a) cout << i.first << ':' << i.second << ' ';
    cout << '\n';
}

void ct(pii a) {
    cout << a.first << ':' << a.second << '\n';
}

void ct(pair<double, int> a) {
    cout << a.first << ':' << a.second << '\n';
}

void ct(vector<pair<double, int>> &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(map<int, int> &a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->fi << ':' << i->se << ' ';
    }
    cout << '\n';
}

void ct(map<string, int> &a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->fi << ':' << i->se << ' ';
    }
    cout << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}

void ci(pii &a) {
    cin >> a.fi >> a.se;
}


void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

const int MOD = 1e9 + 7;
int z[2000000];


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char> (m));
	bool AA = true;
	bool AP = true;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'A')
				AP = false;
			else 
				AA = false;
		}
	}
	if (AA) {
		cout << 0 << '\n';
		return;
	}
	if (AP) {
		cout << "MORTAL" << '\n';
		return;
	}
	bool l = true;
	for(int i = 0; i < n; ++i) {
		if (a[i][0] == 'P')
			l = false;
	}
	if (l) {
		cout << 1 << '\n';
		return;
	}
	l = true;
	for(int i = 0; i < n; ++i) {
		if (a[i][m - 1] == 'P')
			l = false;
	}
	if (l) {
		cout << 1 << '\n';
		return;
	}
	l = true;
	for(int i = 0; i < m; ++i) {
		if (a[0][i] == 'P')
			l = false;
	}
	if (l) {
		cout << 1 << '\n';
		return;
	}
	l = true;
	for(int i = 0; i < m; ++i) {
		if (a[n - 1][i] == 'P')
			l = false;
	}
	if (l) {
		cout << 1 << '\n';
		return;
	}

	if (a[0][0] == 'A') {
		cout << 2 << '\n';
		return;
	}
	if (a[n - 1][0] == 'A') {
		cout << 2 << '\n';
		return;
	}
	if (a[0][m - 1] == 'A') {
		cout << 2 << '\n';
		return;
	}
	if (a[n - 1][m - 1] == 'A') {
		cout << 2 << '\n';
		return;
	}

	for(int i = 0; i < n; ++i) {
		bool l = true;
		for(int j = 0; j < m; ++j) {
			if (a[i][j] == 'P')
				l = false;
		}
		if (l) {
			cout << 2 << '\n';
			return;
		}
	}

	for(int i = 0; i < m; ++i) {
		bool l = true;
		for(int j = 0; j < n; ++j) {
			if (a[j][i] == 'P')
				l = false;
		}
		if (l) {
			cout << 2 << '\n';
			return;
		}
	}

	for(int i = 0; i < n; ++i) {
		if (a[i][0] == 'A') {
			cout << 3 << '\n';
			return;
		}
		if (a[i][m - 1] == 'A') {
			cout << 3 << '\n';
			return;
		}
	}
	for(int i = 0; i < m; ++i) {
		if (a[0][i] == 'A') {
			cout << 3 << '\n';
			return;
		}
		if (a[n - 1][i] == 'A') {
			cout << 3 << '\n';
			return;
		}
	}


	for(int i = 0; i < n; ++i) {
		bool l = true;
		for(int j = 0; j < m; ++j) {
			if (a[i][j] == 'P')
				l = false;
		}
		if (l) {
			cout << 3 << '\n';
			return;
		}
	}

	for(int i = 0; i < m; ++i) {
		bool l = true;
		for(int j = 0; j < n; ++j) {
			if (a[j][i] == 'P')
				l = false;
		}
		if (l) {
			cout << 3 << '\n';
			return;
		}
	}
	cout << 4 << '\n';
}

signed main() {
    setup();
    SOLVE;
}