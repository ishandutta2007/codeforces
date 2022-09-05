#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000001; //check the limits, dummy



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int log[1000001+1];
    log[1] = 0;
    for (int i = 2; i <= 1000001; i++)
        log[i] = log[i/2] + 1;

    int N, W; cin >> N >> W;
    vector<vi> table[N];
    vector<pair<int, pair<int, bool> >> events;
    ll sumMax = 0;
    ll maxVals[N];
    ll sizes[N];
    set<int> lst;
    F0R(T, N) {

        int L; cin >> L;
        vector<vi> cur(L);
        vi data(L);
        sizes[T] = L;
        int mx = -1000000000;
        F0R(i, L) {
            cin >> data[i];
            mx = max(mx, data[i]);
        }
        maxVals[T] = mx;
        vi blank(22); F0R(i, L) cur[i] = blank;

        F0R(i, L) cur[i][0] = data[i];

        //cout <<"got this far" << endl;

        FOR(j, 1, 22) {
            F0R(i, L+1 - (1 << j)) {
                cur[i][j] = max(cur[i][j-1], cur[i + (1 << (j-1))][j-1]);
                //if (cur[i][j] == -100) {
                    //cout << T << " found" << endl;
                //}
            }
        }

        table[T] = cur;
        if (L < (W+1)/2) {
            events.pb(mp(L, mp(T, false)));
            events.pb(mp(W-L, mp(T, true)));
            lst.insert(T);
        } else {
            lst.insert(T);
        }

    }


    sort(all(events));

    int nxt = 0;
    //cout << maxVals[2] << endl;
    F0R(i, W) {
        //cout <<"got this far" << endl;
        while (nxt < sz(events) && events[nxt].f == i) {
            int A = events[nxt].s.f;
            if (events[nxt].s.s) {
                //cout << A << " removed at " << i << endl;
                sumMax -= max(maxVals[A], 0LL);
                lst.insert(A);
            } else {
                sumMax += max(maxVals[A], 0LL);
                lst.erase(A);
            }
            nxt++;
        }
        ll curAns = sumMax;
        //cout << curAns << endl;
        for (auto it = lst.begin(); it != lst.end(); it++) {
            int cur = *it;
            ll start = max(0LL, i - W + sizes[cur]);
            ll end = min(sizes[cur] - 1, (ll) i);
            //cout << cur << " " << start << " " << end << endl;
            int j = log[end - start + 1];
            ll val = max(table[cur][start][j], table[cur][end - (1 << j) + 1][j]);
            if (val < 0 && (i >= sizes[cur] || W-i > sizes[cur])) val = 0;
                curAns += val;
            //cout << curAns << endl;
        }
        //cout << endl;

        cout << curAns << " ";
    }
    cout << endl;




    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE