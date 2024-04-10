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

}

signed main() {
    int n, m;
    cin >> n;
    vpii a;
    fr(i, n) {
        int c;
        cin >> c;
        a.pb(mp(c, -i));
    }
    sort(all(a));
    cin >> m;
    //ct(a);
    fr(i, m) {
        int k, pos;
        vpii ans;
        cin >> k >> pos;
        for(int i = n - k; i < n; ++i) {
            ans.pb(mp(-a[i].se, a[i].fi));
        }
        sort(all(ans));
        //ct(ans);
        cout << ans[pos - 1].se << '\n';
        ans.clear();
    }
}