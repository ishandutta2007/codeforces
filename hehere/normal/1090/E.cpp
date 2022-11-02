#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                                                     \
  {                                                                            \
    cerr << #a << " = {";                                                      \
    for (int qwq = (st); qwq <= (n); ++qwq)                                    \
      if (qwq == (st))                                                         \
        cerr << a[qwq];                                                        \
      else                                                                     \
        cerr << ", " << a[qwq];                                                \
    cerr << "}" << endl;                                                       \
  }
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
#include <ctime>
class MyTimer {
    clock_t st;
public:
    MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
    ~MyTimer() { report(); }
    void reset() { st = clock_t(); }
    void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
    return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }

const int INF = 0x3f3f3f3f;
const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
struct Point {
    int x, y;
    Point(int x = 1, int y = 1) : x(x), y(y) {}
    Point(string s) : x(s[1] - '0'), y(s[0] - 'a' + 1) {}
    string toString() const { string s = "a1"; s[0] = y - 1 + 'a'; s[1] = x + '0'; return s; }
    Point next() const { if(y == 8) return Point(x + 1, 1); else return Point(x, y + 1); }
    friend bool operator != (const Point &x, const Point &y) { return x.x != y.x || x.y != y.y; }
};

int d[9][9];
Point p[9][9];
void BFS(Point s, Point t) {
    memset(d, 0x3f, sizeof(d));
    d[s.x][s.y] = 0;
    queue<Point> Q; Q.push(s);
    while(!Q.empty()) {
        Point f = Q.front(); Q.pop();
        for(int i = 0; i < 8; ++i) {
            Point r(f.x + dx[i], f.y + dy[i]);
            if(!(1 <= r.x && r.x <= 8 && 1 <= r.y && r.y <= 8)) continue;
            if(d[r.x][r.y] == INF) {
                d[r.x][r.y] = d[f.x][f.y] + 1;
                p[r.x][r.y] = f;
                Q.push(r);
            }
        }
    }
    assert(d[t.x][t.y] < INF);
}

int map[9][9], goal[9][9];

void initialize() {
    memset(map, 0, sizeof(map));
    memset(goal, 0, sizeof(goal));
    int k; cin >> k;
    for(int i = 1; i <= k; ++i) {
        string s; cin >> s;
        Point p(s);
        map[p.x][p.y] = 1;
    }
    for(Point p(1, 1); k--; p = p.next()) {
        // cerr << p.toString() << " ";
        goal[p.x][p.y] = 1;
    } cerr << endl;
}

string makeJump(Point s, Point t) {
    return s.toString() + '-' + t.toString();
}

vector<string> ans;

void travel(Point s, Point t) {
    assert(map[s.x][s.y]);
    assert(!map[t.x][t.y]);
    Point _s = s, _t = t;
    // cerr << "Goal : " << " " << makeJump(s, t) << endl;
    BFS(s, t);
    vector<Point> seq;
    while(t != s) seq.push_back(t), t = p[t.x][t.y];
    seq.push_back(s);
    std::reverse(seq.begin(), seq.end());
    for(int i = 1; i < (int)seq.size(); ++i) {
        int j = i;
        while(map[seq[j].x][seq[j].y]) ++j;
        for(int k = j; k >= i; --k) {
            ans.push_back(makeJump(seq[k - 1], seq[k]));
            // cerr << makeJump(seq[k - 1], seq[k]) << endl;
        }
        i = j;
    }
    s = _s; t = _t;
    map[s.x][s.y] = 0; map[t.x][t.y] = 1;
}

void solve() {
    Point idle(1, 1);
    for(Point p(1, 1); p != Point(9, 1); p = p.next()) if(map[p.x][p.y] && !goal[p.x][p.y]) {
        while(map[idle.x][idle.y]) idle = idle.next();
        // cerr << "Hesitate on " << p.toString() << endl;
        // cerr << "Resulting idle " << idle.toString() << endl;
        travel(p, idle); idle = idle.next();
    }
}

int main() {
    initialize();
    solve();
    cout << ans.size() << endl;
    for(string s : ans) cout << s << endl;
    return 0;
}