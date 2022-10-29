#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define forab(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
#define db(x) cout << #x << " = " << x << '\n'
#define pii pair<int, int>

#ifdef LOCAL
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprintf(args...) ;
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = 100179;

pii operator+(pii a, pii b) {
    return {a.X + b.X, a.Y + b.Y};
}

const pii dirs[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int n;

bool correct(pii a) {
    return 0 <= a.X && a.X < n && 0 <= a.Y && a.Y < n;
}

int ask(pii a, pii b) {
    cout << "? " << a.X + 1 << ' ' << a.Y + 1 << ' ' << b.X + 1 << ' ' << b.Y + 1 << '\n';
    cout.flush();

    string ans;
    cin >> ans;
    if (ans == "YES") {
        return 1;
    }
    if (ans == "NO") {
        return 0;
    }
    assert(false);
    return -1;
}

int main() {

    cin >> n;
    pii S[2];
    S[0] = {0, 0};
    S[1] = {n - 1, n - 1};
    vector<pii> paths[2];
    // go down
    forn(i, 2) {
        paths[i].pb(S[i]);
        pii cur = S[i];
        forn(j, n - 1) {
            bool ok = false;
            forn(d, 2) {
                pii ncur = cur + dirs[i * 2 + d];
                bool res = false;
                if (i == 0) {
                    res = ask(ncur, S[i ^ 1]); 
                } else {
                    res = ask(S[i ^ 1], ncur);
                }
                if (res) {
                    ok = true;
                    paths[i].pb(ncur);
                    cur = ncur;
                    break;
                }
            }
            assert(ok);
        }
    }

    assert(paths[0].size() == paths[1].size());
    assert(paths[0].back() == paths[1].back());
    paths[1].pop_back();
    reverse(all(paths[1]));
    for (auto p: paths[1]) {
        paths[0].pb(p);
    }

    cout << "! ";
    for (int i = 0; i < sz(paths[0]) - 1; i++) {
        if (paths[0][i].X == paths[0][i + 1].X) {
            cout << 'R';
        } else {
            cout << 'D';
        }
    }
    cout << '\n';
    cout.flush();

    return 0;
}