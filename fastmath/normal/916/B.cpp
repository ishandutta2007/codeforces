#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    if (bp(n) > k) {
        cout << "No" << endl;
        exit(0);
    }
    map <int, int> cnt;
    FOR (i, 60) {
        if ((n >> i) & 1)
            cnt[i]++;
    }

    int add = k - bp(n);
    for (int i = 60; add; i--) {
        int p = min(cnt[i], add);
        cnt[i] -= p;
        cnt[i - 1] += 2 * p;
        add -= p;
    }

    /*
    trav (e, cnt) {
        if (e.y > 0) {
            debug(mp(e.x, e.y));
        }
    }
    */

    int mx = -1;
    for (int i = 100; ; --i) {
        if (cnt[i] > 0) {
            mx = i;
            break;
        }
    }

    int l = -1;
    for (int i = -100; ; ++i) {
        if (cnt[i] > 0) {
            l = i;
            break;
        }
    }

    cnt[l]--;
    set <int> cand;

        auto check = [&] (int bit) {
            if (cnt[bit] > 1 && bit < mx) {
                cand.insert(bit);
            }
        };
        
    for (int i = -100; i < 100; ++i) {
        if (cnt[i] > 1)
            check(i);
    }

    while (cand.size()) {
        int bit = *cand.begin();
        cand.erase(cand.begin());



        if (cnt[bit] > 1) {
            cnt[bit + 1]++;
            cnt[bit] -= 2;
            cnt[l - 1] += 1;
            check(l - 1);
            check(bit + 1);
            check(bit);
            l--;
        }
    }
    cnt[l]++;

    cout << "Yes" << endl;
    vi ans;
    trav (e, cnt) {
        FOR (i, e.y)
            ans.app(e.x);
    }
    reverse(all(ans));
    cout << ans << endl;
}