#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, fnw[500000];
vector<int> v;
vector<pair<int, int> > swp;
map<int, int> mm;

ll ans;

void add(int i) {
    for (; i < 500000; i += (i & (-i))) {
        fnw[i]++;
    }
}

int get(int i) {
    int ans = 0;
    for (; i > 0; i -= (i & (-i))) {
        ans += fnw[i];
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);

    swp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &swp[i].fs, &swp[i].sc);
        v.pb(swp[i].fs);
        v.pb(swp[i].sc);
    }

    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));
    vector<int> v2 = v;

//    for (auto i : v) {
//        cout << i << ' ';
//    }
//    cout << endl;

    for (int i = 0; i < (int) v.size(); i++) {
        mm[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        swap(v[mm[swp[i].fs]], v[mm[swp[i].sc]]);
    }
//    for (auto i : v2) {
//        cout << i << ' ';
//    }
//    cout << endl;

    for (int i = 0; i < (int) v.size(); i++) {
        ans += abs(v2[i] - i - (v[i] - (int) (lower_bound(all(v2), v[i]) - v2.begin()))) ;
//    cout << (int) (lower_bound(all(v2), v[i]) - v2.begin()) << ' ';
    }
//    cout << endl;


    for (int i = (int) v.size() - 1; i >= 0; i--) {
        ans += get((int) (lower_bound(all(v2), v[i]) - v2.begin()) + 1);
        add((int) (lower_bound(all(v2), v[i]) - v2.begin()) + 1);
    }

    cout << ans << endl;

    return 0;
}