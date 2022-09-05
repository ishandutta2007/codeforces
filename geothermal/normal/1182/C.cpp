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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<string> vals;
    map<int, queue<int> > data[5];
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    F0R(i, N) {
        string cur; cin >> cur;
        vals.pb(cur);
        int count = 0;
        int last = -1;
        F0R(j, sz(cur)) {
            F0R(k, 5) {
                if (cur[j] == vowels[k]) {
                    count++; last =k;
                }
            }
        }
        //cout << count << " " << last << endl;
        if (data[last].count(count)) {
            data[last][count].push(i);
        } else {
            queue<int> blank; blank.push(i);
            data[last].insert(mp(count, blank));
        }
    }


    vpi same;
    map<int, queue<int> > endData;
    F0R(i, 5) {
        for (auto it = data[i].begin(); it != data[i].end(); it++) {
            while (sz(it->s) >= 2) {
                int A = it->s.front(); it->s.pop(); int B = it->s.front(); it->s.pop();
                same.pb(mp(A, B));
            }
            if (sz(it->s) == 1) {
                int nxt = it->s.front();
                if (endData.count(it->f)) {
                    endData[it->f].push(nxt);
                } else {
                    queue<int> blank; blank.push(nxt);
                    endData.insert(mp(it->f, blank));
                }
            }
        }
    }

    vpi similar;

    for (auto it = endData.begin(); it != endData.end(); it++) {
        while (sz(it->s) >= 2) {
            int A = it->s.front(); it->s.pop(); int B = it->s.front(); it->s.pop();
            similar.pb(mp(A, B));
        }
    }

    vector<vi> ans;
    int nxtSim = 0;

    F0R(i, sz(same)) {
        if (nxtSim < sz(similar)) {
            vi cur; cur.pb(similar[nxtSim].f); cur.pb(same[i].f); cur.pb(similar[nxtSim].s); cur.pb(same[i].s);
            nxtSim++;
            ans.pb(cur);
        } else {
            if (i+1 < sz(same)) {
                vi cur;
                cur.pb(same[i + 1].f);
                cur.pb(same[i].f);
                cur.pb(same[i + 1].s);
                cur.pb(same[i].s);
                i++;
                ans.pb(cur);
            }
        }

    }


    cout << sz(ans) << endl;
    F0R(i, sz(ans)) {
        vi cur = ans[i];
        cout << vals[cur[0]] << " " << vals[cur[1]] << endl;
        cout << vals[cur[2]] << " " << vals[cur[3]] << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343