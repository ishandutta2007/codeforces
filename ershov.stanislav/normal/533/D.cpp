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
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

int n;
ll x[N], d[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++) {
        scanf(LLD, &x[i]);
        x[i] *= 2;
    }
    for (int i = 1; i <= n; i++) {
        scanf(LLD, &d[i]);
        d[i] *= 2;
    }
    vector<pair<ll, int> > v1, v2;
    queue<int> q;
    set<ll> cur = {0};
    for (int i = 1; i <= n + 1; i++) {
        cur.insert(i);
        while (q.size()) {
            int r = q.front();
            q.pop();
//            cout << i << " eef " << r << endl;
            if (r != 0 && r != i) {
                set<ll>::iterator r1 = cur.lower_bound(r);
                int right = *(++r1);
                int left = *(--(--r1));
//                cout << left << ' ' << right << endl;
                if (x[right] - x[left] > 2 * d[r]) {
                    cur.erase(r);
                    q.push(left);
                    q.push(right);
                }
            }
        }
        if (i <= n) v1.eb(x[*(++cur.rbegin())] + 2 * d[i], i);
        q.push(i);
    }
    if (cur.size () > 2) {
        cout << 0 << endl;
        return 0;
    }
    while (q.size()) {
        q.pop();
    }
    cur.clear();
    cur = {n + 1};
    for (int i = n; i >= 1; i--) {
        cur.insert(i);
        while (q.size()) {
            int r = q.front();
            q.pop();
//            cout << i << " eef " << r << endl;
            if (r != n + 1 && r != i) {
                set<ll>::iterator r1 = cur.lower_bound(r);
                int right = *(++r1);
                int left = *(--(--r1));
//                cout << left << ' ' << right << endl;
                if (x[right] - x[left] > 2 * d[r]) {
                    cur.erase(r);
                    q.push(left);
                    q.push(right);
                }
            }
        }
        v2.eb(x[*(++cur.begin())] - 2 * d[i], i);
        q.push(i);
    }
    v1.eb(x[n + 1], 0);
    v2.eb(x[0], n + 1);
//    cout << x[n + 1] << endl;
    sort(all(v1));
    sort(all(v2));
//    cout << "v1: \n";
//    for (auto i : v1) {
//        cout << i.fs << ' ' << i.sc << endl;
//    }
//    cout << "v2: \n";
//    for (auto i : v2) {
//        cout << i.fs << ' ' << i.sc << endl;
//    }
//    cout << endl;
    vector<ll> xx;
    for (auto i : v1) {
        if (i.fs > 0 && i.fs < x[n + 1]) {
            xx.pb(i.fs);
        }
    }
    for (auto i : v2) {
        if (i.fs > 0 && i.fs < x[n + 1]) {
            xx.pb(i.fs);
        }
    }
    for (int i = 1; i <= n; i++) {
        xx.pb(x[i]);
    }
    sort(all(xx));
    for (int i = (int) xx.size() - 1; i >= 1; i--) {
        xx.pb((xx[i] + xx[i - 1]) / 2);
    }
    sort(all(xx));
//    for (auto i : xx) {
//        cout << i << endl;
//    }
    vector<ll> mxl(xx.size()), mxr(xx.size());

    set<ll> s1, s2;

    for (int i = (int) xx.size() - 1, j = (int) v1.size() - 1; i >= 0; i--) {
//        cout << "fefw" << endl;
        while (j >= 0 && v1[j].fs >= xx[i]) {
            s1.insert(x[v1[j].sc]);
            j--;
        }
        while (s1.size() && *s1.rbegin() >= xx[i]) {
            s1.erase(*s1.rbegin());
        }
//        cout << "fefw" << s1.size() << ' ' << *s1.rbegin() << endl;
        if (s1.size() >= 1) {
//            cout << "bfedbe" << mxl.size() << endl;
            mxl[i] = xx[i] - *s1.rbegin();
        }
    }

    for (int i = 0, j = 0; i < (int) xx.size(); i++) {
        while (j < (int) v2.size() && v2[j].fs <= xx[i]) {
            s2.insert(x[v2[j].sc]);
            j++;
        }
        while (s2.size() && *s2.begin() <= xx[i]) {
            s2.erase(*s2.begin());
        }
        if (s2.size()) mxr[i] = -xx[i] + *s2.begin();
    }

    ll mn = lINF, mnx = 0;
    for (int i = 0; i < (int) xx.size(); i++) {
//        cout << "i = " << i << ": " << xx[i] << ' ' << mxl[i] << ' ' << mxr[i] << endl;
//        if (mn > mxr + mxl[i]) {
//            mnx = xx[i];
//        }
        mn = min(mn, mxr[i] + mxl[i]);
//        cout << xx[i] << ' ' << ((double) mxr[i] + mxl[i]) / 4 << endl;
    }

    printf("%.10lf", (double) mn / 4);

    return 0;
}