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


signed main() {
    int t;
    cin >> t;
    fr(u, t) {
        int a, b, k;
        cin >> a >> b >> k;
        if (k == 1) {
            cout << "obey" << '\n';
            continue;
        }
        if (a < b) swap(a, b);
        if (a == b) {
            cout << "obey" << '\n';
            continue;
        }
        int z = gcd(a, b);
        a = a / z;
        b = b / z;
        if (b == 1) {
            if (a - 1 >= k) cout << "rebel" << '\n';
            else cout << "obey" << '\n';
            continue;
        }

        if ((a + b - 2) / b >= k) cout << "rebel" << '\n';
        else cout << "obey" << '\n';
    }
}