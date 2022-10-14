#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 1e5 + 5;
int x[N], y[N];

bool cmpx(int i, int j) {return mp(x[i], i) < mp(x[j], j);}
bool cmpy(int i, int j) {return mp(y[i], i) < mp(y[j], j);}
using Cmpx = std::integral_constant<decltype(&cmpx), &cmpx>;
using Cmpy = std::integral_constant<decltype(&cmpy), &cmpy>;
typedef set<int, Cmpx> setX;
typedef set<int, Cmpy> setY;

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> x[i] >> y[i];
    auto solve = [&](setX& X, setY& Y, const auto& self) -> int {
        int ans = 1;
        start:
        auto lx = X.begin(), rx = prev(X.end());
        auto ly = Y.begin(), ry = prev(Y.end());
        rep(_, X.size() / 2) {
            if(x[*next(lx)] - x[*lx] > 1) {
                setX newX;
                setY newY;
                auto nxt = next(lx);
                for(auto itr = X.begin(); itr != nxt; X.erase(itr++)) {
                    newX.insert(*itr);
                    newY.insert(*itr);
                    Y.erase(*itr);
                }
                ans += self(newX, newY, self);
                goto start;
            }
            else lx = next(lx);
            if(y[*next(ly)] - y[*ly] > 1) {
                setX newX;
                setY newY;
                auto nxt = next(ly);
                for(auto itr = Y.begin(); itr != nxt; Y.erase(itr++)) {
                    newX.insert(*itr);
                    newY.insert(*itr);
                    X.erase(*itr);
                }
                ans += self(newX, newY, self);
                goto start;
            }
            else ly = next(ly);
            if(x[*rx] - x[*prev(rx)] > 1) {
                setX newX;
                setY newY;
                for(auto itr = rx; itr != X.end(); X.erase(itr++)) {
                    newX.insert(*itr);
                    newY.insert(*itr);
                    Y.erase(*itr);
                }
                ans += self(newX, newY, self);
                goto start;
            }
            else rx = prev(rx);
            if(y[*ry] - y[*prev(ry)] > 1) {
                setX newX;
                setY newY;
                for(auto itr = ry; itr != Y.end(); Y.erase(itr++)) {
                    newX.insert(*itr);
                    newY.insert(*itr);
                    X.erase(*itr);
                }
                ans += self(newX, newY, self);
                goto start;
            }
            else ry = prev(ry);
        }
        return ans;
    };
    setX X;
    setY Y;
    rep(i, n) X.insert(i), Y.insert(i);
    cout << solve(X, Y, solve) << endl;
}