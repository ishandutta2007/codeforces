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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1000100;

int m, h1, a1, x1, y1, h2, a2, x2, y2;

int start1[N], start2[N], d1[N], d2[N];
int per1, per2;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d%d%d%d%d%d", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
    for (int i = 0; i < N; i++) {
        start1[i] = start2[i] = -1;
    }
    for (int i = 0; i < 2 * N; i++) {
        if (start1[h1] == -1) start1[h1] = i;
        else {
            d1[h1] = 1;
            if (per1 == 0) per1 = i - start1[h1];
        }
        h1 = (x1 * 1ll * h1 + y1) % m;
        if (start2[h2] == -1) start2[h2] = i;
        else {
            d2[h2] = 1;
            if (per2 == 0) per2 = i - start2[h2];
        }
        h2 = (x2 * 1ll * h2 + y2) % m;
    }
//    cout << per1 << ' ' << per2 << endl;
    ll t1 = start1[a1];
    ll t2 = start2[a2];
    if (t1 == -1 || t2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    if (!d1[a1] && !d2[a2]) {
        if (t1 != t2) {
            cout << -1 << endl;
        } else {
            cout << t1;
        }
        return 0;
    }
    if (!d1[a1]) {
        if (t1 < t2 || (t1 - t2) % per2 != 0) {
            cout << -1 << endl;
        } else {
            cout << t1;
        }
        return 0;
    }
    if (!d2[a2]) {
        if (t2 < t1 || (t2 - t1) % per1 != 0) {
            cout << -1 << endl;
        } else {
            cout << t2;
        }
        return 0;
    }
//    for (int i = 0; i < 10; i++) {
//        cout << start1[i] << ' ';
//    }
//    cout << endl;
    while (t1 < t2) {
        t1 += per1;
    }
    for (int i = 0; (t1 - t2) % per2 != 0 && i < 10000000; t1 += per1, i++);
    if ((t1 - t2) % per2 == 0) {
        cout << t1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}