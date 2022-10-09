#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <deque>

#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvvpii vector<vvpii>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
//#define rall(x) x.rbegin(), x.redn()
#define pb push_back
#define mp make_pair
#define con continue
#define eb emplace_back

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

void ct(pair<double, int> &a) {
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

const int inf = 1e9;

vi stec_in = {inf};
vi mn_stec_in = {inf};
vi stec_out = {inf};
vi mn_stec_out = {inf};

void place(int a) {
    stec_in.pb(a);
    mn_stec_in.pb(min(mn_stec_in.back(), a));
}

void del() {
    if (stec_out.size() == 1) {
        while(stec_in.size() > 1) {
            stec_out.pb(stec_in.back());
            mn_stec_out.pb(min(mn_stec_out.back(), stec_in.back()));
            stec_in.pop_back();
            mn_stec_in.pop_back();
        }
    }
    stec_out.pop_back();
    mn_stec_out.pop_back();
}

int get_min() {
    return min(mn_stec_in.back(), mn_stec_out.back());
}

void solve() {
    string s;
    cin >> s;
    vi a(s.size());
    int n = s.size();
    fr(i, n) {
        if (s[i] == 'a') a[i] = 2;
        if (s[i] == 'b') a[i] = 1;
        if (s[i] == 'c') a[i] = 0;
        if (s[i] == '?') a[i] = -1;
    }
    if (n == 1) {
        if (s[0] == '?') cout << 'a' << '\n';
        return;
    }
    int l = a[0];
    for(int i = 1; i < n; ++i) {
        if (a[i] == l && a[i] != -1) {
            cout << -1 << '\n';
            return;
        }
        l = a[i];
    }
    //ct(a);
    if (a[0] == -1) a[0] = (a[1] + 1) % 3;
    for(int i = 1; i < n; ++i) {

        if (a[i] == -1) a[i] = (a[i - 1] + 1) % 3;
    }
    for(int i = 1; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            a[i] = 3 - a[i - 1] - a[i + 1];
        }
    }
    //ct(a);
    fr(i, n) {
        if (a[i] == 0) cout << 'c';
        if (a[i] == 1) cout << 'b';
        if (a[i] == 2) cout << 'a';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    fr(i, t) solve();
}