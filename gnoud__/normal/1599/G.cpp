#include <bits/stdc++.h>

using namespace std;

#define in ({int x = 0; int c = getchar(), n = 0; for(; !isdigit(c); c = getchar()) n = (c == '-'); for(; isdigit(c); c = getchar()) x = x * 10 + c - '0'; n ? -x : x;})

#define forinc(a, b, c) for(int a = b, _c = c; a <= _c; ++a)
#define fordec(a, b, c) for(int a = b, _c = c; a >= _c; --a)
#define forv(a, b) for(auto &a : b)
#define reset(a, b) memset(a, b, sizeof a)
#define all(a) a.begin(), a.end()

#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define gg exit(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return l + rng() % (r - l + 1);
}

const int N = 200010;
const long double EPS = 1e-9;

int n, k;
struct pt {
    int x, y, i;
} p[N];

long double dist(int i, int j) {
    return sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
}

bool inq(int i, int j, int t) {
    if(fabs(dist(i, j) + dist(j, t) - dist(i, t)) < EPS)
        return true;
    if(fabs(dist(i, t) + dist(t, j) - dist(i, j)) < EPS)
        return true;
    if(fabs(dist(i, t) + dist(i, j) - dist(j, t)) < EPS)
        return true;
    return false;
}

int tim(int x, int y) {
    int imp = 0, cnt = 0;
    forinc(i, 1, n) if(i != x && i != y) {
        if(!inq(i, x, y)) {
            cnt++;
            imp = i;
        }
    }
    return cnt == 1 ? imp : 0;
}

main() {
#define task "TASK"
    if(fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    n = in, k = in;
    forinc(i, 1, n) p[i] = {in, in, i};

    sort(p + 1, p + n + 1, [](pt i, pt j) {
        return make_pair(i.x, i.y) < make_pair(j.x, j.y);
    });

    int f = tim(1, 2);
    if(!f)
        f = tim(n - 1, n);
    //if(!f)
    //return cout << setprecision(6) << fixed << dist(1, n) << "\n", 0;
    if(!f)
        f = 1;
    swap(p[f], p[n]);
    n--;
    sort(p + 1, p + n + 1, [](pt i, pt j) {
        return make_pair(i.x, i.y) < make_pair(j.x, j.y);
    });

    int l = 1;
    int r = n;
    f = n + 1;

    if(p[n + 1].i == k)
        k = n + 1;
    else
        forinc(i, 1, n) if(p[i].i == k) {
            k = i;
            break;
        }

    long double kflr = dist(k, f) + dist(f, l) + dist(l, r);
    long double kfrl = dist(k, f) + dist(f, r) + dist(r, l);
    long double klfr = dist(k, l) + dist(l, f) + dist(f, min(r, k + 1 + (f == k + 1))) + dist(min(r, k + 1 + (f == k + 1)), r);
    long double krfl = dist(k, r) + dist(r, f) + dist(f, max(l, k - 1 - (k - 1 == f))) + dist(max(l, k - 1 - (k - 1 == f)), l);
    long double klrf = dist(k, l) + dist(l, r) + dist(r, f);
    long double krlf = dist(k, r) + dist(r, l) + dist(l, f);

    forinc(m, 1, n - 1) {
        long double le = dist(k, l) + dist(l, m) + dist(m, f) + dist(f, m + 1) + dist(m + 1, r);
        long double ri = dist(k, r) + dist(r, m + 1) + dist(m + 1, f) + dist(f, m) + dist(m, l);
        krlf = min({krlf, le, ri});
    }

    cout << setprecision(6) << fixed << min({kflr, kfrl, klfr, krfl, klrf, krlf}) << "\n";

    return 0;
}