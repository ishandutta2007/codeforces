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
const int MX = 100001;

ll sum[262144], lazy[262144]; //Lazy segtree implementation inspired by bqi343's Github contributions

void push(int index, ll L, ll R) {
    sum[index] += (R - L + 1) * (lazy[index]);
    if (L != R) lazy[2*index] += lazy[index], lazy[2*index+1] += lazy[index];
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = sum[2*index] + sum[2*index+1];
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = 131071) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return query(lo, hi, 2*index, L, M) + query(lo, hi, 2*index+1, M+1, R);
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = 131071) {
    //push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    F0R(i, 262144) {
        sum[i] = 0;
        lazy[i] = 0;
    }

    int n, q; cin >> n;
    set<int> components;
    F0R(i, n) {
        components.insert(i);
        ll cur; cin >> cur;
        update(i, i, cur);
        //cout << sum[131072] << endl;
    }
    components.insert(n);

    ll k[n-1], prefix[n];
    prefix[0] = 0;
    FOR(i, 1, n) {
        ll cur; cin >> cur;
        prefix[i] = prefix[i-1] + cur;
    }

    /*F0R(i, n) {
        cout << query(i, i) << endl;
    }*/


    cin >> q;
    F0R(queryNumber, q) {
        char c; cin >> c;
        if (c == '+') {
            int index; ll increase; cin >> index >> increase; index--;
            //update(index, index, increase);
            ll val = query(index, index) + increase;
            vi toBeErased;
            if (components.count(index) == 0) components.insert(index);
            int next = index;


            for(auto it = components.upper_bound(index); it != components.end(); it++) {
                int cur = *it;
                update(next, cur-1, prefix[next] - prefix[index] + val - query(next, next));
                if (cur == n) break;
                //cout << "Querying " << cur << " " << query(cur, cur) << endl;
                if (query(cur, cur) <= val + prefix[cur] - prefix[index]) {
                    toBeErased.pb(cur);
                    next = cur;
                } else {
                    break;
                }
            }

            F0R(i, sz(toBeErased)) {
                components.erase(toBeErased[i]);
            }


        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            cout << query(a, b) << endl;
        }
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343