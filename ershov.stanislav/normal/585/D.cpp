#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 40;

int a[N], b[N], c[N];

struct ans{
    vector<int> moves;
    int a;
    ans() {
        a = 0;
        moves = vector<int>();
    }
};
vector<pair<pair<int, int>, ans> > m1, m2;

bool operator<(const ans & a, const ans & b) {
    return a.a < b.a;
}

void brute1(int pos, int lft, ans & cur, int ab, int bc) {
    if (lft == 0) {
        m1.eb(mp(ab, bc), cur);
    } else {
        {
            int nab = ab + a[pos] - b[pos];
            int nbc = bc + b[pos];
            cur.a += a[pos] + b[pos];
            cur.moves.pb(0);
            brute1(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= a[pos] + b[pos];
            cur.moves.pop_back();
        }
        {
            int nab = ab + a[pos];
            int nbc = bc - c[pos];
            cur.a += a[pos] + c[pos];
            cur.moves.pb(1);
            brute1(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= a[pos] + c[pos];
            cur.moves.pop_back();
        }
        {
            int nab = ab - b[pos];
            int nbc = bc + b[pos] - c[pos];
            cur.a += b[pos] + c[pos];
            cur.moves.pb(2);
            brute1(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= b[pos] + c[pos];
            cur.moves.pop_back();
        }
    }
}

void brute2(int pos, int lft, ans & cur, int ab, int bc) {
    if (lft == 0) {
        m2.eb(mp(ab, bc), cur);
    } else {
        {
            int nab = ab + a[pos] - b[pos];
            int nbc = bc + b[pos];
            cur.a += a[pos] + b[pos];
            cur.moves.pb(0);
            brute2(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= a[pos] + b[pos];
            cur.moves.pop_back();
        }
        {
            int nab = ab + a[pos];
            int nbc = bc - c[pos];
            cur.a += a[pos] + c[pos];
            cur.moves.pb(1);
            brute2(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= a[pos] + c[pos];
            cur.moves.pop_back();
        }
        {
            int nab = ab - b[pos];
            int nbc = bc + b[pos] - c[pos];
            cur.a += b[pos] + c[pos];
            cur.moves.pb(2);
            brute2(pos + 1, lft - 1, cur, nab, nbc);
            cur.a -= b[pos] + c[pos];
            cur.moves.pop_back();
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
    ans ll, rr;
    brute1(0, n / 2, ll, 0, 0);
    brute2(n / 2, n - n / 2, rr, 0, 0);
    sort(all(m1));
    sort(all(m2));
    ans res;
    res.a = -INF;
    ans BIG;
    BIG.a = INF;
//    for (auto i : m1) {
//        cout << i.fs.fs << ' ' << i.fs.sc << ' ' << i.sc.a << endl;
//        for (auto j : i.sc.moves) {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (auto i : m2) {
//        cout << i.fs.fs << ' ' << i.fs.sc << ' ' << i.sc.a << endl;
//        for (auto j : i.sc.moves) {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
    for (auto i : m1) {
        auto it = upper_bound(all(m2), mp(mp(-i.fs.fs, -i.fs.sc), BIG));
        if (it == m2.begin()) {
            continue;
        }
        it--;
        if (it->fs.fs == -i.fs.fs && it->fs.sc == -i.fs.sc) {
            if (res.a < i.sc.a + it->sc.a) {
                res.a = i.sc.a + it->sc.a;
                res.moves.clear();
                for (auto j : i.sc.moves) {
                    res.moves.pb(j);
                }
                for (auto j : it->sc.moves) {
                    res.moves.pb(j);
                }
            }
        }
    }
    if (res.a == -INF) {
        printf("Impossible");
    } else {
        for (auto j : res.moves) {
            if (j == 0) {
                printf("LM\n");
            }
            if (j == 1) {
                printf("LW\n");
            }
            if (j == 2) {
                printf("MW\n");
            }
        }
    }
    return 0;
}