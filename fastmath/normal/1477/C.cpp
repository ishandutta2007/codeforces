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
#define debug(x) std::cout << #x << ": " << x << '\n';
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

struct pt {
    int x, y;
    pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
    int operator%(const pt &p) const { return x * p.x + y * p.y; }
    int operator*(const pt &p) const { return x * p.y - y * p.x; }
    pt operator*(const int &a) const { return pt{x * a, y * a}; }
    bool operator==(const pt &p) const { return mp(x, y) == mp(p.x, p.y); }
    bool operator<(const pt &p) const {
        if (x != p.x)
            return x < p.x;
        if (y != p.y)
            return y < p.y;
        return false;
    }
    int abs2() const { return x * x + y * y; }
};
ostream &operator<<(ostream &out, const pt &p) { return out << "(" << p.x << ' ' << p.y << ")"; }
int dist(pt a, pt b) {
    return (a-b).abs2();
}   


signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    V <pt> a(n);
    vi ans;

    auto sign = [&] (int x) {
        if (x > 0)
            return 1;
        else if (x == 0)
            return 0;
        else
            return -1;
    };

    auto bad = [&] (pt a, pt b, pt c) {
        auto v = b - a;
        pt rv = {-v.y, v.x};
        //auto bb = b + rv;

        //debug(sign(rv * (a - b)));
        //debug(sign(rv * (c - b)));

        return sign(rv * (a - b)) * sign(rv * (c - b)) <= 0;
    };

/*
    pt A = {0, 0};
    pt B = {3, 3};
    pt C = {7, 3};
    cout << bad(C, B, A) << endl;
    exit(0);
*/
    FOR (i, n) {
        cin >> a[i].x >> a[i].y;
        int pos = ans.size();
        ans.app(i);
        while (pos >= 2 && bad(a[ans[pos - 2]], a[ans[pos - 1]], a[ans[pos]])) {
            swap(ans[pos], ans[pos - 1]);
            pos--;
        }
    }

    //debug(bad(a[1], a[2], a[3]));
    //exit(0);

    trav (e, ans)
        cout << e + 1 << ' ';
    cout << endl;
}