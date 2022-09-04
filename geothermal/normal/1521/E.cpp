#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int N, K;
int A[MX];
vector<vi> res;

bool ok(int L) {
    if (N > L*L-((L/2)*(L/2))) return false;
    res = vector<vi>(L, vi(L, 0));
    int cnt[K]; F0R(i, K) cnt[i] = A[i];
    priority_queue<pi> q;
    F0R(i, K) {
        q.push({cnt[i], i});
    }

    F0R(i, L) {
        F0R(j, L) {
            if (i%2 == 0 && j%2 == 0) {
                if (q.top().f <= 0) continue;
                res[i][j] = q.top().s+1;
                cnt[q.top().s]--;
                q.push({cnt[q.top().s], q.top().s});
                q.pop();
            }
        }
    }

    int T = (L/2)*((L+1)/2);
    vi p1, p2;
    vector<pi> vals; F0R(i, K) vals.pb({cnt[i], i});
    sort(all(vals)); reverse(all(vals));
    int ext = -1;

    trav(asdf, vals) {
        int cur = asdf.s;
        if (sz(p1) <= sz(p2)) {
            if (sz(p1) + cnt[cur] <= T) {
                F0R(i, cnt[cur]) p1.pb(cur+1);
            } else {
                if (ext != -1) return false;
                ext = cur;
            }

        } else {
            if (sz(p2) + cnt[cur] <= T) {
                F0R(i, cnt[cur]) p2.pb(cur+1);
            } else {
                if (ext != -1) return false;
                ext = cur;
            }
        }
    }

    if (ext != -1) {
        F0R(i, cnt[ext]) {
            if (sz(p1) <= sz(p2)) {
                p1.pb(ext+1);
            } else p2.pb(ext+1);
        }
    }

    reverse(all(p1)); reverse(all(p2));
    int p = 0;
    F0R(i, L) {
        F0R(j, L) {
            if (i%2==0 && j%2 == 1) {
                if (p < sz(p1)) res[i][j] = p1[p];
                p++;
            }
        }
    }
    p = 0;
    F0Rd(i, L) {
        F0Rd(j, L) {
            if (i%2 == 1 && j%2 == 0) {
                if (p < sz(p2)) res[i][j] = p2[p];
                p++;
            }
        }
    }


    F0R(i, L-1) {
        F0R(j, L) {
            if (res[i][j] != 0 && ((j > 0 && res[i][j] == res[i+1][j-1]) || (j < L-1 && res[i][j] == res[i+1][j+1]))) {
                return false;
            }
        }
    }



    return true;

}

void solve() {
    cin >> N >> K;
    F0R(i, K) cin >> A[i];
    int lo = 1, hi = 1;
    while (hi*hi < 2*N+10) hi++;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        //cout << "Test " << lo << " " << hi << " " << mid << nl;
        if (ok(mid)) {
            hi = mid;
        } else lo = mid+1;
    }
    ok(lo);

    cout << lo << nl;
    F0R(i, lo) {
        F0R(j, lo) {
            cout << res[i][j] << " ";
        }
        cout << nl;
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}