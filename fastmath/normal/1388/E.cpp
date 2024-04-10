#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define double long double

using my_float = double;
  
struct point {
    my_float x, y;
 
    point() : x(0), y(0) {}
 
    point(my_float _x, my_float _y) : x(_x), y(_y) {}
 
    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};
 
my_float cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}
 
bool left_turn(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) > 0;
}

// dp_hull enables you to do the following two operations in amortized O(log n) time:
// 1. Insert a pair (a_i, b_i) into the structure
// 2. For any value of x, query the maximum value of a_i * x + b_i
// All values a_i, b_i, and x can be positive or negative.
struct dp_hull {
    struct segment {
        point p;
        mutable point next_p;
 
        segment(point _p = {0, 0}) : p(_p), next_p(_p) {}
 
        bool operator<(const point &other) const {
            return other.x * (next_p.x - p.x) > (p.y - next_p.y) * other.y;
        }
 
        bool operator<(const segment &other) const {
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };
 
    set<segment, less<>> segments;
 
    int size() const {
        return (int)segments.size();
    }
 
    set<segment, less<>>::iterator prev(set<segment, less<>>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }
 
    set<segment, less<>>::iterator next(set<segment, less<>>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }
 
    bool bad(set<segment, less<>>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() && !left_turn(next(it)->p, it->p, prev(it)->p);
    }
 
    void insert(const point &p) {
        auto next_it = segments.lower_bound(segment(p));
 
        if (next_it != segments.end() && p.x == next_it->p.x)
            return;
 
        if (next_it != segments.begin()) {
            auto prev_it = prev(next_it);
 
            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() && !left_turn(next_it->p, p, prev_it->p))
                return;
        }
 
        auto it = segments.insert(next_it, segment(p));
 
        while (bad(prev(it)))
            segments.erase(prev(it));
 
        while (bad(next(it)))
            segments.erase(next(it));
 
        if (it != segments.begin())
            prev(it)->next_p = it->p;
 
        if (next(it) != segments.end())
            it->next_p = next(it)->p;
    }
 
    void insert(my_float a, my_float b) {
        insert(point(a, b));
    }
 
    // Queries the maximum value of ax + by.
    my_float query(my_float x, my_float y = 1) const {
        assert(size() > 0);
        assert(y > 0);
        auto it = segments.lower_bound(point(x, y));
        return it->p.x * x + it->p.y * y;
    }
};

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    struct Seg {
        int l, r, y;
    };  
    vector <Seg> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].y;
    }   
    auto comp = [] (Seg a, Seg b) {
        return a.y < b.y;
    };  
    sort(all(a), comp);
    double INF = 5e18;
    struct Event {
        double x;
        int d;
    };  
    vector <Event> sc;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].y < a[j].y) {
                double h = a[j].y - a[i].y;
                double l = (a[i].l - a[j].r) / h;
                double r = (a[i].r - a[j].l) / h;
                sc.app({l, -1});
                sc.app({r, 1});
            }   
        }   
    }   
    auto comp_ev = [] (Event a, Event b) { return a.x < b.x || (a.x == b.x && a.d > b.d); };  
    sort(all(sc), comp_ev);
    cout.precision(20);
    vector <double> c;
    int cur = 0;
    for (auto e : sc) {
        bool good = cur == 0;
        cur += e.d;
        good |= cur == 0;
        if (good)
            c.app(e.x);
    }
    dp_hull l, r;
    for (auto e : a) {
        l.insert(-e.y, -e.l);
        r.insert(e.y, e.r);
    }   

    if (c.empty())
        c = {0};

    double ans = INF;
    for (auto e : c) {
        ans = min(ans, r.query(e) + l.query(e));
    }   
    cout << ans << endl;
}