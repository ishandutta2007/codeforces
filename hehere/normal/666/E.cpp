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

const int maxM = 50000 + 233;
const int maxN = 500000 + maxM;
const int maxQ = 500000 + 233;
int n, m, q;
string s;
string t[maxM];
int tql[maxQ], tqr[maxQ];
pii ans[maxQ];
int ql, qr;
struct SuffixAutomaton {
    struct TNode;
    struct Node {
        Node *last, *ch[26], *jump[21];
        TNode *tree;
        int len;
        vector<int> qs;
        Node() : last(nullptr), tree(nullptr), len(0)
            { memset(ch, 0, sizeof(ch)); memset(jump, 0, sizeof(jump)); qs.clear(); }
    } *root, pool[maxN * 2], *newnode, *now;
    Node *pos[maxN];
    struct TNode {
        pii max;
        TNode *lson, *rson;
        TNode() { max = pii(0, 0); lson = rson = nullptr; }
        void maintain() {
            max = pii(0, 0);
            if(lson) chmax(max, lson->max);
            if(rson) chmax(max, rson->max);
        }
        pii query(int L, int R) {
            if(ql <= L && R <= qr) {
                return max;
            } else {
                pii res(0, -ql);
                int M = (L + R) >> 1;
                if(ql <= M && lson) chmax(res, lson->query(L, M));
                if(qr > M && rson) chmax(res, rson->query(M + 1, R));
                return res;
            }
        }
        void DFS(int L, int R) {
            if(L == R) printf("pos = %d, val = %d, %d\n", L, max.first, max.second);
            else {
                int M = (L + R) >> 1;
                if(lson) lson->DFS(L, M);
                if(rson) rson->DFS(M + 1, R);
            }
        }
    };
    TNode* create() {
        static TNode *pool; static int len = 0;
        if(len == 0) pool = new TNode[65536], len = 65536;
        return pool + (--len);
    }
    TNode* merge(TNode* x, TNode* y, int L, int R) {
        if(x == nullptr) return y;
        if(y == nullptr) return x;
        if(L == R) {
//            printf("pos = %d(%d), freq = %d + %d = %d\n", L, x->max.second, x->max.first, y->max.first, x->max.first + y->max.first);
            x->max.first += y->max.first;
        } else {
            int M = (L + R) >> 1;
            x->lson = merge(x->lson, y->lson, L, M);
            x->rson = merge(x->rson, y->rson, M + 1, R);
            x->maintain();
        }
        return x;
    }
    void insert(TNode* &o, int L, int R, int pos) {
        if(o == nullptr) o = create();
        if(L == R) {
            o->max.first++; o->max.second = -L;
            // for chmax
        } else {
            int M = (L + R) >> 1;
            if(pos <= M) insert(o->lson, L, M, pos);
            else insert(o->rson, M + 1, R, pos);
            o->maintain();
        }
    }
    void clear() {
        root = newnode = now = pool;
        *root = Node();
        newnode++;
    }
    void insert(const string &s, int id) {
        now = root;
        for(int i = 0; i < (int)s.length(); ++i) {
            extend(s[i] - 'a', i + 1);
            if(id) insert(now->tree, 1, m, id);
            else pos[i + 1] = now;
        }
    }
    void mark(const string &s, int id) {
        now = root;
        for(int i = 0; i < (int)s.length(); ++i) {
            now = now->ch[int(s[i] - 'a')];
            if(id) insert(now->tree, 1, m, id);
            else pos[i + 1] = now;
        }
    }
    void prepareToJump() {
        for(Node *p = root + 1; p != newnode; ++p) p->jump[0] = p->last;
        for(int k = 1; k < 21; ++k)
            for(Node *p = root + 1; p != newnode; ++p)
                p->jump[k] = p->jump[k - 1] ? p->jump[k - 1]->jump[k - 1] : nullptr;
    }
    int c[maxN];
    Node *p[maxN * 2];
    void sort() {
        memset(c, 0, sizeof(c));
        for(Node *o = root + 1; o != newnode; ++o) c[o->len]++;
        for(int i = 1; i < maxN; ++i) c[i] += c[i - 1];
        for(Node *o = root + 1; o != newnode; ++o) p[c[o->len]--] = o;
    }
    void solveAll() {
        int cnt = newnode - root - 1;
        sort();
//        printf("\nOverview:\n\n");
//        for(int i = cnt; i >= 1; --i) {
//            Node *u = p[i];
//            printf("Current node len = %d, last->len = %d\n", u->len, u->last->len);
//            if(u->tree) u->tree->DFS(1, m);
//            printf("\n");
//        }
        
        for(int i = cnt; i >= 1; --i) {
            Node *u = p[i];
//            printf("Current: node with len = %d, last->len = %d\n", u->len, u->last->len);
            for(int x : u->qs) {
//                printf("Handling Query %d, tree below:\n", x);
//                if(u->tree) u->tree->DFS(1,  m);
                ql = tql[x]; qr = tqr[x];
                ans[x] = u->tree ? u->tree->query(1, m) : pii(0, -ql);
            }
            
//            printf("len = %d, last->len = %d\n", u->len, u->last->len);
//            printf("Before merging:\n");
//            u->tree->DFS(1, m);
//            printf("Another:\n");
//            u->last->tree->DFS(1, m);
//            printf("Then:\n");
            u->last->tree = merge(u->last->tree, u->tree, 1, m);
//            printf("After:\n");
//            u->last->tree->DFS(1, m);
//            printf("\n\n");
        }
    }
    void extend(int c, int curLen) {
        if(now->ch[c]) {
            if(now->ch[c]->len == now->len + 1) {
                now = now->ch[c];
            } else {
                Node *p = now, *q = now->ch[c], *clone = newnode++;
                *clone = *q; clone->tree = nullptr;
                clone->len = p->len + 1;
                q->last = clone; now = clone;
                for(; p && p->ch[c] == q; p = p->last) p->ch[c] = clone;
            }
            return;
        }
        Node *p = newnode++; std::swap(p, now);
        now->len = curLen;
        for(; p && p->ch[c] == nullptr; p = p->last) p->ch[c] = now;
        if(!p) { now->last = root; return; }

        Node *q = p->ch[c];
        if(q->len == p->len + 1) {
            now->last = q;
        } else {
            Node *clone = newnode++; *clone = *q;
            clone->len = p->len + 1; clone->tree = nullptr;
            q->last = now->last = clone;
            for(; p && p->ch[c] == q; p = p->last) p->ch[c] = clone;
        }
    }
}sam;

/*
abccd
3
abccbcdcccd
abcdabcdccc
cdbcccbecbc
2
1 3 3 4
2 3 1 3

ab
2
ab
babab
2
1 2 1 2
2 2 1 1
*/

int main() {
    std::ios::sync_with_stdio(false);
    sam.clear();
    cin >> s; sam.insert(s, 0); n = s.length();
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> t[i], sam.insert(t[i], i);
//    sam.mark(s, 0);
//    for(int i = 1; i <= m; ++i) sam.mark(t[i], i);
//    displaya(t, 1, m);
    sam.prepareToJump();
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> tql[i] >> tqr[i];
        int l, r; cin >> l >> r;
        SuffixAutomaton::Node* now = sam.pos[r];
        for(int k = 20; k >= 0; --k) if(now->jump[k] && now->jump[k]->len >= r - l + 1) {
            now = now->jump[k];
        }
//        printf("len = %d, last->len = %d\n", now->len, now->last->len);
        now->qs.push_back(i);
    }
    sam.solveAll();
    for(int i = 1; i <= q; ++i)
        printf("%d %d\n", -ans[i].second, ans[i].first);
    return 0;
}