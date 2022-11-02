#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
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
using std::bitset; using std::map;
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
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
    int a = 0; char c = getchar(), p = 0;
    while(isspace(c)) c = getchar();
    if(c == '-') p = 1, c = getchar();
    while(isdigit(c)) a = a*10 + c - '0', c = getchar();
    return p ? -a : a;
}

const int maxN = 200000 * 2 + 233; // for nodes
char str[maxN];
int s[maxN];
int n;
struct SuffixAutomaton {
    int ch[maxN][27], len[maxN], last[maxN];
    int root, now, newnode;    

    void init() {
        memset(ch, 0, sizeof(ch));
        memset(len, 0, sizeof(len));
        memset(last, 0, sizeof(last));
        root = now = 1;
        newnode = 1;
        for(int i = 1; i <= n; ++i) extend(s[i], i);
    }

    void extend(int c, int curLen) {
        int p = ++newnode; std::swap(p, now); len[now] = curLen;
        for(; p && ch[p][c] == 0; p = last[p]) ch[p][c] = now;
        if(p == 0) { last[now] = root; return; }

        int q = ch[p][c];
        if(len[p] + 1 == len[q]) {
            last[now] = q;
        } else {
            int clone = ++newnode;
            memcpy(ch[clone], ch[q], sizeof(ch[clone]));
            last[clone] = last[q]; len[clone] = len[p] + 1;
            last[now] = clone; last[q] = clone;
            for(; p && ch[p][c] == q; p = last[p]) ch[p][c] = clone;
        }
    }

    int dfs_clock;
    int pos[maxN]; // suffix No. -> vertex
    vector<int> G[maxN];
    int pre[maxN], f[20][maxN], dep[maxN];

    void DFS(int u) {
        pre[u] = ++dfs_clock;
        for(int v : G[u]) {
            dep[v] = dep[u] + 1;
            f[0][v] = u;
            DFS(v);
        }
    }

    void buildTree() {
        for(int u = 2; u <= newnode; ++u) G[last[u]].push_back(u);
        dfs_clock = 0;
        dep[1] = 1; f[0][1] = 0; DFS(1);
        for(int k = 1; k < 20; ++k)
            for(int u = 1; u <= newnode; ++u)
                f[k][u] = f[k - 1][f[k - 1][u]];
        int u = 1;
        for(int i = 1; i <= n; ++i) {
            u = ch[u][s[i]];
            pos[i] = u; // on reversed suffix tree
        }
        displaya(len, 1, newnode);
        displaya(last, 1, newnode);
        displaya(pre, 1, newnode);
        displaya(pos, 1, n);
    }

    int LCA(int x, int y) {
        if(dep[x] < dep[y]) std::swap(x, y);
        int dif = dep[x] - dep[y];
        for(int i = 19; i >= 0; --i) if(dif >> i & 1) x = f[i][x];
        for(int i = 19; i >= 0; --i) if(f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
        return x == y ? x : f[0][x];
    }

    int A[maxN], B[maxN], pa[maxN];
    LL count[maxN];
    bool isLeaf[maxN];
    vector<int> lst;
    vector<int> all;

    LL solve() {
        int ca, cb; scanf("%d%d", &ca, &cb);
        lst.clear(); all.clear();
        for(int i = 1; i <= ca; ++i) {
            int x; scanf("%d", &x); x = pos[n + 1 - x];
            A[x]++; isLeaf[x] = true;
            lst.push_back(x);
        }
        for(int i = 1; i <= cb; ++i) {
            int x; scanf("%d", &x); x = pos[n + 1 - x];
            B[x]++; isLeaf[x] = true;
            lst.push_back(x);
        }
        std::sort(lst.begin(), lst.end(), [&](int x, int y) {
            return pre[x] < pre[y];
        });
        lst.erase(std::unique(lst.begin(), lst.end()), lst.end());
        static int stk[maxN * 2]; int stklen = 0;
        stk[stklen = 1] = 1;
        for(int u : lst) {
            int lca = LCA(u, stk[stklen]);
            // printf("LCA %d %d = %d\n", u, stk[stklen], lca);
            while(stklen > 1 && dep[lca] <= dep[stk[stklen - 1]]) {
                all.push_back(stk[stklen]);
                pa[stk[stklen]] = stk[stklen - 1];
                stklen--;
            }
            if(lca != stk[stklen]) {
                all.push_back(stk[stklen]);
                pa[stk[stklen]] = lca;
                stk[stklen] = lca;
            }
            stk[++stklen] = u;
        }
        for(int i = 1; i + 1 <= stklen; ++i) pa[stk[i + 1]] = stk[i];
        all.insert(all.end(), stk + 1, stk + stklen + 1);
        std::sort(all.begin(), all.end(), [&](int x, int y) {
            return dep[x] > dep[y];
        });
        LL ans = 0;
        for(int u : all) {
            if(isLeaf[u]) ans += (A[u] * (LL)B[u]) * (LL)(len[u] - 1);
            else ans += (A[u] * (LL)B[u] - count[u]) * (LL)len[u];
            A[pa[u]] += A[u]; B[pa[u]] += B[u];
            count[pa[u]] += A[u] * (LL)B[u];
        }
        for(int u : all) count[u] = A[u] = B[u] = 0, isLeaf[u] = false;
        return ans;
    }

} sam;

int main() {
    int q;
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);
    str[++n] = '$';
    for(int i = 1; i <= n; ++i) {
        if(isalpha(str[i])) s[n + 1 - i] = str[i] - 'a' + 1;
        else s[n + 1 - i] = 0;
    }
    sam.init(); sam.buildTree();
    while(q--) printf("%lld\n", sam.solve());
    return 0;
}