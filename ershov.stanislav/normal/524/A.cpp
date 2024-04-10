#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#define next _next
#define prev _prev
#define hash _hash
#define all(s) s.begin(), s.end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    int m, k;
    scanf("%d%d", &m, &k);
    map<int, set<int> > v;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        s.insert(a);
        s.insert(b);
        v[a].insert(b);
        v[b].insert(a);
    }
    for (auto i : s) {
        vector<int> ans;
        for (auto j : s) {
            int cnt = 0;
            if (j == i || v[i].count(j)) {
                continue;
            }
            for (auto k : v[j]) {
                if (v[i].count(k)) {
                    cnt++;
                }
            }
            if (cnt * 100 >= v[i].size() * k) {
                ans.pb(j);
            }
        }
        printf("%d: ", i);
        printf("%d ", (int) ans.size());
        for (auto j : ans) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}