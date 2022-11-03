#include <bits/stdc++.h>

#define f first
#define s second
#define int long long

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = 10;

/*
*/

vector<int> get(vector<pair<int, char>> s) {
	int n = s.size();
	vector<int> p(n);

	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j])
			j = p[j - 1];

		if (s[i] == s[j])
            j++;
		p[i] = j;
	}

	return p;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, char>> a, b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        char c;
        cin >> c;
        cin >> c;

        if(!a.empty() && a.back().s == c) {
            a.back().f += x;
        } else {
            a.emplace_back(x, c);
        }
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        char c;
        cin >> c;
        cin >> c;

        if(!b.empty() && b.back().s == c) {
            b.back().f += x;
        } else {
            b.emplace_back(x, c);
        }
    }

    n = a.size();
    m = b.size();

    if(m == 1) {
        li ans = 0;
        for(auto p : a)
            if(p.s == b[0].s)
                ans += max(0ll, p.f - b[0].f + 1);
        cout << ans << endl;
        return 0;
    }

    if(m == 2) {
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i].s == b[0].s && a[i + 1].s == b[1].s && a[i].f >= b[0].f && a[i + 1].f >= b[1].f) {
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<pair<int, char>> c;
    for(int i = 1; i < m - 1; i++)
        c.push_back(b[i]);

    c.emplace_back(-1, 'a');

    for(auto p : a)
        c.push_back(p);

    int ans = 0;
    vector<int> p = get(c);
    for(int i = m; i < c.size() - 1; i++) {
        if(p[i] == m - 2) {
            int j = i - m + 2;
            if(c[j].s == b[0].s && c[i + 1].s == b[m - 1].s &&
               c[j].f >= b[0].f && c[i + 1].f >= b[m - 1].f)
                    ans++;
        }
    }

    cout << ans << endl;
}