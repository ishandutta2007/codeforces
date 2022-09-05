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

string S;

ll countAt(int K) { //inspired by geeksforgeeks
    if (K == 0) return 1;
    if (sz(S) == K) return 1;
    int N = sz(S);
    if (K == 1) {
        set<int> included;
        F0R(i, N) {
            included.insert(S[i] - 'a');
        }
        return included.size();
    }

    vl vec1(N), vec2(N), vec3(26);
    F0R(i, N) {
        vec1[i] = 0; vec2[i] = 0;

    }
    F0R(i, 26) vec3[i] = 0;

    vec2[N-1] = 1;
    vec3[S[N-1] - 'a'] = 1;

    F0Rd(i, N-1) {
        vec2[i] = vec2[i+1];
        if (vec3[S[i] - 'a'] == 0) {
            vec2[i]++;
            vec3[S[i] - 'a'] = 1;
        }
    }

    FOR(i, 1, K) {
        fill(all(vec3), 0);
        vec1[N-1] = 0;

        F0Rd(i, N-1) {
            vec1[i] = vec1[i+1];
            vec1[i] += vec2[i+1];
            vec1[i] -= vec3[S[i] - 'a'];
            vec3[S[i] - 'a'] = vec2[i+1];
        }
        F0R(i, N) vec2[i] = vec1[i];
    }

    return vec1[0];

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; ll K;
    cin >> N >> K;
    cin >> S;

    ll count[N+1];

    F0R(i, N+1) {
        count[i] = countAt(i);
    }

    ll ans = 0;
    F0Rd(i, N+1) {
        if (count[i] >= K) {
            ans += K * (N - i);
            break;
        } else {
            ans += count[i] * (N - i);
            K -= count[i];
        }

        if (i == 0) {
            cout << -1 << endl; return 0;
        }

    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343