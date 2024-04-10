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
#define ffr(i, m, n) for(int i = m; i < n; ++i)
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

void ct(set<int> &a) {
    for(auto i: a) cout << i << ' ';
    cout << '\n';
}

void ct_ans(vpii &a) {
    for(auto i: a) {
        cout << i.fi << ' ' << i.se << '\n';
    }
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

void ci(vpii &a) {
    for(auto &i: a) ci(i);
}

bool check(vvi &trap, int min_ch, int len, int skoka) {
    int k = trap.size();
    vpii tr;
    fr(i, k) {
        if (trap[i][2] > min_ch) {
            if (trap[i][0] > trap[i][1]) continue;

            tr.pb(mp(trap[i][0], -1));
            tr.pb(mp(trap[i][1], 1));
        }
    }
    if (tr.size() == 0) return true;
    sort(all(tr));
    int n = tr.size();
    int bal = 0, last = 0;
    int t = 0;
    int x = 0;
    fr(i, n) {
        if (bal == 0) {
            last = tr[i].fi - 1;
        }
        bal -= tr[i].se;
        if (bal == 0) {
            t += (tr[i].fi - last);
            //last = tr[i].fi;
        }
    }
    t *= 2;
    t = len + 1 + t;
    if (t <= skoka) return true;
    else return false;
}

signed main() {
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vi a(m);
    ci(a);
    sort(all(a));
    reverse(all(a));
    vpii pol(n);
    vvi trap(k, vi (3));
    fr(i, k) {
        cin >> trap[i][0] >> trap[i][1] >> trap[i][2];
    }
    int l = -1, r = m, mid;
    while(r - l > 1) {
        mid = (l + r) / 2;
        bool c = check(trap, a[mid], n, t);
        if (c) l = mid;
        else r = mid;
    }
    cout << l + 1;
}