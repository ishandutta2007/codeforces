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

const int maxN = 250000 + 233;
const pii NONE(-maxN, -maxN);
int n, m;
unsigned seed = 123321;
struct Node {
    pii v;
    int c, s;
    unsigned r;
    Node *ch[2];
    Node() {}
    Node(pii val) : v(val), c(1), s(1), r(seed *= 321123) { ch[0] = ch[1] = NULL; }
    void maintain() {
        s = c + (ch[0] ? ch[0]->s : 0) + (ch[1] ? ch[1]->s : 0);
    }
};
Node *backup[maxN];
Node *create(pii val = NONE) {
    static Node *bin; static int len = 0;
    if(len == 0) bin = new Node[len = 65536];
    bin[--len] = Node(val);
    return &bin[len];
}

#define SZ(o) ((o) ? (o)->s : 0)

void DFS(Node *o, int d = 0) {
    if(d == 0) printf("=====Treap=====\n");
    for(int i = 0; i < d; ++i) printf("  ");
    if(o == NULL) printf("->NULL\n");
    else {
        printf("->v = [%d, %d], s = %d, c = %d, r = %u, add = 0x%llx\n",
            o->v.first, o->v.second, o->s, o->c, o->r, (long long)o);
        DFS(o->ch[0], d + 1);
        DFS(o->ch[1], d + 1);
    }
    if(d == 0) printf("=====Endin=====\n");
}

void merge(Node *&x, Node *L, Node *R) {
    if(L == NULL && R == NULL) {
        x = NULL; return;
    }
    x = create();
    if(L == NULL) *x = *R;
    else if(R == NULL) *x = *L;
    else {
        if(L->r < R->r) {
            x = create(); *x = *L;
            merge(x->ch[1], L->ch[1], R);
            x->maintain();
        } else {
            x = create(); *x = *R;
            merge(x->ch[0], L, R->ch[0]);
            x->maintain();
        }
    }
}

void split(Node *o, pii k, Node *&L, Node *&R) {
    if(o == NULL) L = NULL, R = NULL;
    else {
        if(o->v <= k) {
            L = create(); *L = *o;
            split(o->ch[1], k, L->ch[1], R);
            L->maintain();
        } else {
            R = create(); *R = *o;
            split(o->ch[0], k, L, R->ch[0]);
            R->maintain();
        }
    }
}

void remove(Node *o, Node *&n, pii val) {
    if(o == NULL && !(n = o)) return;
    else {
//		DFS(o);
        n = create();
        *n = *o;
        if(val < o->v) remove(o->ch[0], n->ch[0], val);
        else if(val == o->v) {
            if(n->c > 1) n->c--, n->s--;
            else {
                merge(n, n->ch[0], n->ch[1]);
            }
        }
        else remove(o->ch[1], n->ch[1], val);
        if(n) n->maintain();
    }
}

void insert(Node *root, Node *&cur, pii x) {
    Node *L, *R;
    split(root, x, L, R);
    Node *o = create(x);
    merge(cur, L, o);
    merge(cur, cur, R);
}

pii getMax(Node *o) {
    if(o == NULL) return NONE;
    else return std::max(o->v, getMax(o->ch[1]));
}
pii find(Node *o, int val) {
    if(o == NULL) return NONE;
    if(o->v.first <= val && val <= o->v.second) return o->v;
    if(val < o->v.first) return find(o->ch[0], val);
    else return find(o->ch[1], val);
}

struct Creature {
    int a, h, round;
    Node *root; int delta;
    Creature() : a(0), h(0), round(-1), root(NULL), delta(0) {}
    bool attackToDeath(int att) {
        att -= delta;
        pii p = find(root, att);
        if(p == NONE) { // just insert
            pii pre = find(root, att - 1);
            pii post = find(root, att + 1);
            int l = att, r = att;
            if(pre != NONE) l = pre.first, remove(root, root, pre);
            if(post != NONE) r = post.second, remove(root, root, post);
            insert(root, root, pii(l, r));
        } else { // remove something
            remove(root, root, p);
            if(p.first <= att - 1) insert(root, root, pii(p.first, att - 1));
            pii post = find(root, p.second + 2);
            if(post == NONE) {
                insert(root, root, pii(p.second + 1, p.second + 1));
            } else {
                remove(root, root, post);
                insert(root, root, pii(p.second + 1, post.second));
            }
        }
        // printf("Health = %d, get attacked by %d\n", h, att + delta);
        // printf("Now, delta = %d, and the tree:\n", delta); DFS(root);
        return getMax(root).second + delta >= h;
    }
} p[maxN];

void process(int R) {
    int op = readint();
    if(op == 1) { // create blank
        p[++m] = Creature();
    } else if(op == 2) { // double the attack
        int id = readint();
        if(p[id].round == -1) p[id].a++;
    } else if(op == 3) { // double the health
        int id = readint();
        if(p[id].round == -1) p[id].h++, p[id].delta++;
    } else if(op == 4) { // create by copy
        int id = readint();
        p[++m] = p[id];
        if(p[id].round != -1) p[m].round = R;
    } else if(op == 5) { // fight
        int x = readint(), y = readint();
        if(p[x].round != -1 || p[y].round != -1) return;
        if(p[x].attackToDeath(p[y].a)) p[x].round = R;
        if(p[y].attackToDeath(p[x].a)) p[y].round = R;
    }
}

int main() {
    n = readint();
    m = 0;
    for(int i = 1; i <= n; ++i)
        process(i);
    printf("%d\n", m);
    for(int i = 1; i <= m; ++i)
        printf("%d%c", p[i].round, " \n"[i == m]);
    return 0;
}