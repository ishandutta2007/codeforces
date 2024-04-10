#include <bits/stdc++.h>

/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> sett;*/

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

char f(char c, char d) {
    if ('a' != c && 'a' != d)
        return 'a';
    if ('b' != c && 'b' != d)
        return 'b';
    return 'c';
}

signed main() {
    setup();
    
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    int a1 = k, a2 = k;
    vector<char> ans(n);
    vector<int> pref(n + 2);
    for(int i = n - 1; i >= 0; --i) {
        if (s1[i] == s2[i]) 
            pref[i] = pref[i + 1];
        else 
            pref[i] = pref[i + 1] + 1;
    }
    for(int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if (a1 > a2) {
                ans[i] = s1[i];
                --a1;
            }
            else if (a1 == a2) {
                if ((pref[i + 1] + 1) / 2 > (a1 - 1)) {
                    ans[i] = s2[i];
                    --a2;
                }
                else {
                    ans[i] = f(s2[i], s1[i]);
                    --a1, --a2;
                }
            }
            else {
                ans[i] = s2[i];
                --a2;
            }
        }
        //cout << a1 << ' ' << a2 << '\n';
    }
    for(int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) {
            if (a1 == a2 && a1 != 0) {
                ans[i] = f(s2[i], s1[i]);
                --a1;
                --a2;
            }
            else {
                ans[i] = s2[i]; 
            }
        }
    }
    if (a1 != 0 || a2 != 0) {
        cout << -1;
        return 0;
    }
    for(auto i: ans)
        cout << i;
}