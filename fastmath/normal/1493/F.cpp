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

const int N = 2007;
bool p[N];

signed main() {
    for (int i = 2; i < N; ++i)
        p[i] = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            for (int j = i * 2; j < N; j += i) {
                p[j] = 0;
            }
        }
    }

    int n, m;
    cin >> n >> m;


    map <vi, int> mem;

    auto ask = [&] (int h, int w, int x1, int y1, int x2, int y2) {
        vi q = {h, w, x1, y1, x2, y2};
        if (mem.count(q))
            return mem[q] == 1;
        cout << "? " << h << ' ' << w << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        int ans;
        cin >> ans;
        mem[q] = ans;
        return ans == 1;
    };

    auto check_r = [&] (int r) {
        int k = n/r;

        if (k == 2) {
            return ask(n/2, m, 1, 1, n/2+1, 1);
        }

        if (k & 1) {
            int ha = k/2;
            return ask(r * ha, m, 1, 1, r * (ha + 1) + 1, 1) 
            && ask(r * ha, m, 1, 1, (r * ha) + 1, 1);
        }
        else {
            int ha = k/2;
            return ask(r * ha, m, 1, 1, (r * ha) + 1, 1) 
            && ask(r * (ha - 1), m, 1, 1, r * (ha - 1) + 1, 1);
        }
    };

    int r = n;
    for (int d = 2; d <= r; ++d) {
        if (p[d]) {
            while (r % d == 0 && check_r(r/d))
                r /= d;
        }
    }

    auto check_c = [&] (int c) {
        int k = m/c;

        //debug(c);
        //debug(k);

        if (k == 2) {
            return ask(n, m/2, 1, 1, 1, m/2+1);
        }

        if (k & 1) {
            int ha = k/2;
            return ask(n, c * ha, 1, 1, 1, c * (ha + 1) + 1)
            && ask(n, c * ha, 1, 1, 1, c * ha + 1);
        }
        else {
            int ha = k/2;
            return ask(n, c * ha, 1, 1, 1, c * ha + 1) 
            && ask(n, c * (ha - 1), 1, 1, 1, c * (ha - 1) + 1);
        }
    };

    int c = m;
    for (int d = 2; d <= c; ++d) {
        if (p[d]) {
            while (c % d == 0 && check_c(c/d)) {
                c /= d;
            }
        }
    }

    auto count_div = [&] (int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (n % i == 0)
                ans++;
        return ans;
    };

    cout << "! " << count_div(n/r) * count_div(m/c) << endl;
}