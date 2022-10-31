#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

const int maxn = 6.1e5;
const int max1 = maxn * 4, max2 = maxn * 4, max3 = maxn * 20;
int bigcnt;
int n, q;
char s[maxn];
int starts[maxn];

struct big {
  int left, right;

  pair<int, int> dp;

  big() {
    left = right = -1;
    dp = mp(0, 1);
  }
};

big bigs[max3];

struct node {
  node * link, **go;
  int len;
  int mx, mn, used;
  int isterm;
  int id;
  int cnt;
  int bigid;

  node(int len);
};

int cntgo;
node *allgo[max1][27];

node::node(int len = 0) : len(len) {
  link = 0; 
  mx = -inf, mn = inf, used = 0;
  isterm = 0;
  cnt = 0;
}

node nodes[max2];
int cntnodes;

node * makenode(int len = 0) {
  assert(cntnodes < max2);
  node * ans = nodes + (cntnodes++);
  *ans = node(len);
  ans->id = cntnodes - 1;
  bigs[bigcnt] = big();
  assert(bigcnt < max3);
  ans->bigid = bigcnt++;
  assert(cntgo < max1);
  ans->go = allgo[cntgo++];
  memset(ans->go, 0, 27 * sizeof(node*));
  //eprintf("%d\n", cntgo);
  return ans;
}

struct SuffixAutomaton {
  int todelete;
  node * root, * all;
  vector<vector<int> > left, right;
  int n;
  vector<vector<node *> > nodelen;

  SuffixAutomaton(int todelete = 1) : todelete(todelete) {

  }

  void addc(int c) {
    node * v = makenode(all->len + 1);
    swap(v, all);
    while (v && !(v->go[c])) {
      v->go[c] = all;
      v = v->link;
    }
    if (!v) {
      all->link = root;
    } else {
      node * u = v->go[c];
      if (u->len == v->len + 1) {
        all->link = u;
        return;
      }
      node * clone = makenode(v->len + 1);
      memcpy(clone->go, u->go, 27 * sizeof(node *));
      clone->link = u->link;
      all->link = u->link = clone;
      while (v && v->go[c] == u) {
        v->go[c] = clone;
        v = v->link;
      }
    }
  }

  void dfs(node * v) {
    //eprintf("%d\n", v->id);
    if (v->used) {
      return;
    }
    v->used = true;
    if (v->isterm) {
      v->mx = v->mn = 0;
    }
    for (int i = 0; i < 27; i++) {
      if (v->go[i]) {
        dfs(v->go[i]);
        v->mx = max(v->mx, v->go[i]->mx + 1);
        v->mn = min(v->mn, v->go[i]->mn + 1);
        v->cnt += v->go[i]->cnt;
        /*if (v->id == 94) {
          eprintf("%c\n", i + 'a');
        }*/
      }
    }
    nodelen[v->len].pb(v);
  }

  void build(int l, int r) {
    int wasgo = cntgo;
    //eprintf("%d %d\n", l, r);
    n = r - l;
    //eprintf("%d\n", n);
    root = makenode();
    all = root;
    for (int i = l; i < r; i++) {
      addc(s[i] - 'a');
    }
    for (node * v = all; v; v = v->link) {
      v->isterm = 1;
      v->cnt = 1;
    }
    left = right = vector<vector<int> > (n + 1);
    nodelen = vector<vector<node *> > (n + 1);
    //eprintf("!\n");
    dfs(root);
    //eprintf("!\n");
    for (int i = 0; i <= n; i++) {
      for (auto j : nodelen[i]) {
        left[n - j->mx].pb(j->id);
        right[n - j->mn].pb(j->id);
      }
    }
    if (todelete) {
      cntgo = wasgo;
    }
  }
};

bool read() {
  starts[0] = 0;
  if (scanf("%s%d", s, &n) < 2) {
    return false;
  }
  starts[1] = strlen(s) + 1;
  s[starts[1] - 1] = 'z' + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + starts[i]);
    starts[i + 1] = starts[i] + strlen(s + starts[i]) + 1;
    s[starts[i + 1] - 1] = 'z' + 1;
  //eprintf("%d\n", i);
  }
  return true;
}

int getmid(int l, int r) {
  int mid = (starts[l] + starts[r]) / 2;
  int m = (int) (lower_bound(starts + l, starts + r, mid) - starts);
  if (m == l) {
    m++;
  } else if (m == r) {
    m--;
  }
  assert(m > l && m < r);
  return m;
}

void buildtree(int l, int r, SuffixAutomaton & suff) {
  //eprintf("%d %d\n", l, r);
  suff.build(starts[l], starts[r]);
  /*for (int i = starts[l]; i < starts[r]; i++) {
    eprintf("%c", s[i]);
  }
  eprintf("\n");
  int cur = suff.root->id;
  string togo = "b";
  for (int i = 0; i < sz(togo); i++) {
    node * nxt = nodes[cur].go[togo[i] - 'a'];
    if (!nxt) {
      cur = -1;
      break;
    }
    cur = nxt->id;
  }
  eprintf("l = %d, r = %d, cur = %d, curbig = %d\n", l, r, cur, nodes[cur].bigid);*/
  if (l == r - 1) {
    for (int i = 0; i <= suff.n; i++) {
      for (auto j : suff.left[i]) {
        int bigid = nodes[j].bigid;
        bigs[bigid].dp = mp(nodes[j].cnt, -l);
      }
    }
  } else {
    int mid = getmid(l, r);
    SuffixAutomaton leftsuff, rightsuff;
    int cntwas = cntnodes;
    buildtree(l, mid, leftsuff);
    vector<int> ptrleft(starts[r] - starts[l] + 1);
    for (int i = 0; i <= leftsuff.n; i++) {
      for (auto j : suff.left[i]) {
        big & curbig = bigs[nodes[j].bigid];
        vector<int> & curarr = leftsuff.left[i];
        int & curptr = ptrleft[i];
        while (curptr < sz(curarr) && nodes[curarr[curptr]].len < nodes[j].len) {
          curptr++;
        }
        if (curptr < sz(curarr)) {
          curbig.left = nodes[curarr[curptr]].bigid;
          curbig.dp = max(curbig.dp, bigs[curbig.left].dp);
        }
      }
    }
    cntnodes = cntwas;
    buildtree(mid, r, rightsuff);
    vector<int> ptrright(starts[r] - starts[l] + 1);
    for (int i = leftsuff.n, k = mid; i <= suff.n; i++) {
      while (k < r && starts[k + 1] - starts[l] <= i) {
        k++;
      }
      for (auto j : suff.right[i]) {
        big & curbig = bigs[nodes[j].bigid];
        vector<int> curarr = rightsuff.right[i - leftsuff.n];
        int & curptr = ptrright[i];
        /*if (j == 383) {
          eprintf("%d %d %d\n", i - leftsuff.n, curptr, nodes[j].len);
        }*/
        while (curptr < sz(curarr) && nodes[curarr[curptr]].len < nodes[j].len && i - starts[k] + starts[l] > nodes[curarr[curptr]].len) {
          curptr++;
        }
        /*if (j == 383) {
          eprintf("%d %d %d\n", starts[k], curptr, nodes[curarr[curptr]].len);
        }*/
        if (curptr < sz(curarr)) {
          curbig.right = nodes[curarr[curptr]].bigid;
          curbig.dp = max(curbig.dp, bigs[curbig.right].dp);
        }
      }
    }
    cntnodes = cntwas;
  }
}

pair<int, int> query(int bigid, int vl, int vr, int l, int r) {
  /*eprintf("bigid = %d, vl = %d, vr = %d\n", bigid, vl, vr);
  eprintf("%d %d\n", bigs[bigid].dp.first, bigs[bigid].dp.second);
  eprintf("bigleft = %d, bigright = %d\n", bigs[bigid].left, bigs[bigid].right);*/
  //eprintf("l = %d, r = %d\n", l, r);
  if (bigid == -1) {
    return mp(0, 1);
  }
  if (vr <= l || r <= vl) {
    return mp(0, 1);
  }
  if (l <= vl && vr <= r) {
    return bigs[bigid].dp;
  } else {
    int mid = getmid(vl, vr);
    return max(query(bigs[bigid].left, vl, mid, l, r), query(bigs[bigid].right, mid, vr, l, r));
  }
}

void solve() {
  cntnodes = 0;
  bigcnt = 0;
  cntgo = 0;
  SuffixAutomaton suff(0);
  //eprintf("!\n");
  buildtree(0, n + 1, suff);
  //eprintf("!\n");
  vector<int> prefix(starts[1]);
  prefix[0] = suff.root->id;
  for (int i = 0; i < starts[1] - 1; i++) {
    prefix[i + 1] = nodes[prefix[i]].go[s[i] - 'a']->id;
  }
  vector<vector<int> > jump(20, vector<int> (cntnodes));
  //eprintf("mx[96] = %d\n", nodes[96].mx);
  //eprintf("len[96] = %d\n", nodes[96].len);
  //eprintf("cnt[96] = %d\n", nodes[96].cnt);
  //eprintf("Yeah!\n");
  for (int i = 0; i < cntnodes; i++) {
    node * link = nodes[i].link;
    jump[0][i] = link ? link->id : -1;
  }
  //eprintf("Yeah!\n");
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < cntnodes; j++) {
      int one = jump[i - 1][j];
      if (one == -1) {
        jump[i][j] = -1;
      } else {
        jump[i][j] = jump[i - 1][one];
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int t = 0; t < q; t++) {
    int l, r, pl, pr;
    scanf("%d%d%d%d", &l, &r, &pl, &pr);
    r++, pl--;
    //eprintf("pr = %d\n", pr);
    int node = prefix[pr];
    for (int i = 19; i >= 0; i--) {
      if (jump[i][node] != -1 && nodes[jump[i][node]].len >= pr - pl) {
        node = jump[i][node];
      }
      //eprintf("len[node] = %d\n", nodes[node].len);
    }
    //eprintf("node = %d\n", node);
    //eprintf("bigid = %d\n", nodes[node].bigid);
    pair<int, int> res = query(nodes[node].bigid, 0, n + 1, l, r);
    printf("%d %d\n", res.second == 1 ? l : -res.second, res.first);
  }
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}