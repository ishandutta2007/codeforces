#include <bits/stdc++.h>

#define int ll
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


signed main() {
    int t;
    cin >> t;
    fr(i, t) {
        init;
        vi a(n);
        ci(a);
        vi b(n);
        ci(b);
        bool o = false;
        bool z = false;
        bool p = false;
        int k = 0;
        fr(i, n) {
            a[i] -= b[i];
            a[i] = -a[i];
            //cout << z << ' ' << p << '\n';
            if (a[i] < 0) {
                cout << "NO";
                o = 1;
                break;
            }
            if (a[i] == 0 && k != 0 && z) {
                cout << "NO";
                o = 1;
                break;
            }
            if(a[i] == 0 && k != 0) {
                z = 1;
                k = 0;
            }
            else if(a[i] != 0 && z && p) {
                //cout << k << ' ';
                cout << "NO";
                o = 1;
                break;
            }
            if(a[i] != 0 && k == 0) {
                k = a[i];
                p = 1;
            }
            if(a[i] != 0 && a[i] != k) {
                cout << "NO";
                o = 1;
                break;
            }
        }
        //cout << o;
        //ct(a);
        if (!o) cout << "YES";
        cout << '\n';
        z = false;
        o = false;
    }
}