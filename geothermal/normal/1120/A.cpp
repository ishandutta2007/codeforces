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
const int MX = 500001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int M, K, N, S; cin >> M >> K >> N >> S;

    int data[M]; F0R(i, M) cin >> data[i];

    int* req = new int[MX];
    F0R(i, MX) {
        req[i] = 0;
    }

    F0R(i, S) {
        int cur; cin >> cur;
        req[cur]++;
    }

    int* counts = new int[MX];
    F0R(i, MX) counts[i] = 0;

    int total = 0;

    counts[data[0]]++;
    int start = 0;
    if (req[data[0]] >= 1) total = 1;
    if (total == S) {
        cout << "0" << endl;
        return 0;
    }
    bool found = false;
    int beg, end;
    int cutA, cutB;
    FOR(i, 1, M) {
        //assume impossible, add next
        counts[data[i]]++;
        if (counts[data[i]] <= req[data[i]]) {
            total++;
        }


        while (total == S) {
            found = true;
            counts[data[start]]--;
            if (counts[data[start]] < req[data[start]]) {
                total--;
            }
            start++;
        }

        if (found) {
            beg = start-1; end = i;

            int len = end-beg+1;
            int cut = max(0, len-K);
            cutA = cut;
            end = end - cut;
            int lastPos;
            if (end >= N*K-1) {
                lastPos = N * K - 1;
            } else if  (beg / K == end / K) {
                lastPos = end;
            } else {
                if (end % K == K-1) {
                    lastPos = end;
                } else {
                    int val = end / K;
                    val = val * K; val--;
                    lastPos = val;
                }
            }

            cut += end - lastPos;
            cutB = end - lastPos;
            end = i;

            if (M - cut >= N*K) {
                break;
            }

        }
        found = false;
    }

    if (!found) {
        cout << -1 << endl;
        return 0;
    }

    cout << cutA + cutB << endl;
    F0R(i, cutB) {
        cout << i+1 << " ";
    }

    F0R(i, MX) counts[i] = 0;


    FOR(i, beg, end+1) {
        if (cutA == 0) break;
        counts[data[i]]++;
        if (counts[data[i]] > req[data[i]]) {
            cout << i+1 << " "; cutA--;
        }

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343