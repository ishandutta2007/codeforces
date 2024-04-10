#include <bits/stdc++.h>

//#define int ll
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define ll long long
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

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

void ct(set<pii> &a) {
    for(auto &i: a) cout << i.first << ':' << i.second << ' ';
    cout << '\n';
}

void ct(pii &a) {
    cout << a.first << ':' << a.second << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}

void f(int l, int r, vi &a) {
    vi c;
    for(int i = l; i <= r; ++i) {
        c.pb(a[i]);
    }
    reverse(all(c));
    //ct(c);
    //ct(a);
    int j = 0;
    for(int i = l; i <= r; ++i) {
        a[i] = c[j];
        ++j;
    }
}

void think() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    fr(i, n) {
        char c;
        cin >> c;
        if (c == '(') a[i] = 1;
        else a[i] = -1;
    }
    vpii ans;
    vi pos(n);
    fr(i, k - 1) {
        pos[2 * i] = 1;
        pos[2 * i + 1] = -1;
    }
    for(int i = 2 * k - 2; i < n - (n - 2 * (k - 1)) / 2; ++i) {
        pos[i] = 1;
    }
    for(int i = n - (n - 2 * (k - 1)) / 2; i < n; ++i) pos[i] = -1;
    //ct(a);
    //ct(pos);

    fr(i, n) {
        if (a[i] != pos[i]) {
            for(int j = i + 1; j < n; ++j) {
                if (a[j] == pos[i]) {
                    ans.pb(mp(i + 1, j + 1));
                    f(i, j, a);
                    break;
                    //ct(a);
                    //cout << i << ' ' << j << '\n';
                }
            }
        }
    }
    cout << ans.size() << '\n';
    fr(i, ans.size()) {
        cout << ans[i].fi << ' ' << ans[i].se << '\n';
    }
}

signed main() {
    itn t;
    cin >> t;
    fr(i, t) think();
}