#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int w, h, n;
set<int> x, y;
multiset<int> mx, my;
vector<long long> ans;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &w, &h, &n);
    x.insert(0);
    x.insert(w);
    y.insert(0);
    y.insert(h);
    mx.insert(-w);
    my.insert(-h);
    for (int i = 0; i < n; i++) {
        string t;
        int p;
        cin >> t >> p;
        if (t == "V") {
            auto j = x.lower_bound(p);
            auto k = j;
            k--;
            int len = (*j) - (*k);
            mx.erase(mx.lower_bound(-len));
            mx.insert(-p + (*k));
            mx.insert(-(*j) + p);
            x.insert(p);
        } else {
            auto j = y.lower_bound(p);
            auto k = j;
            k--;
            int len = (*j) - (*k);
            my.erase(my.lower_bound(-len));
            my.insert(-p + (*k));
            my.insert(-(*j) + p);
            y.insert(p);
        }
        ans.pb( (*(mx.begin())) * 1ll * (*(my.begin())) );
    }
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}