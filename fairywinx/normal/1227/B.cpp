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

void think() {
    int n;
    cin >> n;
    set<int> q;
    fr(i, n) q.insert(i + 1);
    int last = 0;
    int a;
    cin >> a;
    last = a;
    vi ans;
    ans.pb(a);
    q.erase(a);
    for(int i = 0; i < n - 1; ++i) {
        /*for(auto i: q) cout << i << ' ';
        cout << '\n';*/
        cin >> a;
        //ct(ans);
        //cout << 'H';
        if (a == last) {
            ans.pb(*q.begin());
            //cout << *q.begin() << ' ';
            if (last < *q.begin()) {
                for(int j = i + 1; j < n - 1; ++j) cin >> a;
                cout << -1 << '\n';
                return;
            }
            q.erase(*q.begin());
        }
        else {
            ans.pb(a);
            //cout << a << ' ';
            if (q.count(a) == 0) {
                for(int j = i + 1; j < n - 1; ++j) cin >> a;
                cout << -1 << '\n';
                return;
            }
            q.erase(a);
        }
        last = a;
    }
    ct(ans);
}

signed main() {
    int t;
    cin >> t;
    fr(i, t) think();
}