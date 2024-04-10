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

void ct(set<int> &a) {
    for(auto i: a) cout << i << ' ';
    cout << '\n';
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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    ci(a);
    int g = 0, b = 0, s = 0;
    map<int, int> z;
    fr(i, n) {
        if (!z.count(a[i])) z[a[i]] = 0;
        z[a[i]]++;
    }
    //ct(z);
    g = z.rbegin()->se;
    for(auto i = z.rbegin(); i != z.rend(); ++i) {
        if (i == z.rbegin()) con;
        if (s <= g) s += i->se;
        else {
            if (b + i->se + g + s <= n / 2) {
                b += i->se;
            }
            else break;
        }
    }
    //cout << g << ' ' << s << ' ' << b << '\n';
    if (g >= s || g >= b) {
        cout << "0 0 0\n";
        return;
    }
    if (g + s + b > n / 2) cout << "0 0 0\n";
    else cout << g << ' ' << s << ' ' << b << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    fr(i, t) solve();
}