#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
const ld EPS = 1E-12;
 
struct pt {
    ld x, y;
};
 
struct seg {
    pt p, q;
    int id;
 
    ld get_y(ld x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};
 
bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}
 
int vec(const pt& a, const pt& b, const pt& c) {
    ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}
 
bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}
 
bool operator<(const seg& a, const seg& b)
{
    ld x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    if (a.get_y(x) + EPS < b.get_y(x)) {
        return true;
    } else if (b.get_y(x) + EPS < a.get_y(x)) {
        return false;
    }
    return a.id < b.id;
}
 
struct event {
    ld x;
    int tp, id;
 
    event() {}
    event(ld x, int tp, int id) : x(x), tp(tp), id(id) {}
 
    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};
 
set<seg> s;
vector<set<seg>::iterator> where;
 
set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}
 
set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}
 
pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());
/*    F0R(i, 2*n) {
        cout << e[i].x << " " << e[i].tp << " " << e[i].id << endl;
    }*/
 
    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
//        cout << i << " " << id << endl;
        if (e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
//            cout << "BEF " << nxt->id << " " << sz(s) << endl;
            where[id] = s.insert(nxt, a[id]);
//            cout << "AFT " << nxt->id << " " << sz(s) << endl;
//            cout << where[id]->id << " " << a[id].id << endl;
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            //cout << "START" << endl;
            s.erase(where[id]);
            //cout << "END" << endl;
        }
//        cout << sz(s) << endl;
    }
 
    return make_pair(-1, -1);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vector<pt> points;
    ld dx[N], dy[N];
    F0R(i, N) {
        ld X, Y; cin >> X >> Y;
        points.pb({X, Y});
        ld A, B, C; cin >> A >> B >> C;
        ld M = sqrt(A*A+B*B);
        
        if (M < 0.5) {
            dx[i] = 0; dy[i] = 0; continue;
        }
        A /= M; B /= M; A *= C; B *= C;
        dx[i] = A; dy[i] = B;
    }
 
    ld lo = 0;
    ld hi = 1e16;
    while(hi - lo > 1e-8) {
//        cout << "TESTit" << " " << it << " " << lo << " " << hi << endl;
        ld mid = (lo+hi)/2;
        vector<seg> A;
        F0R(i, N) {
            pt sta = points[i];
            pt end = {points[i].x + dx[i] * mid, points[i].y + dy[i] * mid};
//            cout << sta.x << " " << sta.y << " " << end.x << " " << end.y << nl;
            A.pb({sta, end, i});
        }
        if (solve(A).f == -1) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (lo > 7e15)
 { 
        cout << "No show :(" << nl;
    } else {
        cout << setprecision(20) << lo << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343