#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1e5 + 100;
const int maxm = 10e6;

struct node {
  int l, r;
  ll mn, toadd;

  node () : l(0), r(0), mn(0), toadd(0) {}
  node (const node & b) {
    l = b.l;
    r = b.r;
    mn = b.mn;
    toadd = b.toadd;
  }

  void add(ll val) {
    mn += val, toadd += val;
  }
};

int n, k;
int w[maxn], g[maxn];
int goright[maxn], goleft[maxn];
ll balright[maxn], balleft[maxn];
node nodes[maxm];
int cntnodes;

int getnode(int a, int b) {
  int res = cntnodes++;
  nodes[res].l = a, nodes[res].r = b;
  nodes[res].toadd = 0;
  nodes[res].mn = min(nodes[a].mn, nodes[b].mn);
  return res;
}

int val1[maxn], val2[maxn];

int st[maxn], stsz;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", w + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", g + i);
  }
  return true;
}

/*bool read() {
  n = 30000;
  k = 1e9;
  for (int i = 0; i < n; i++) {
      w[i] = rnd(1e9);
      g[i] = rnd(1e9);
  }
  return true;
}*/

int build(int l, int r) {
  int res = cntnodes++;
  nodes[res] = node();
  if (l < r - 1) {
    int mid = (l + r) / 2;
    nodes[res].l = build(l, mid);
    nodes[res].r = build(mid, r);
  }
  return res;
}

int buildzero(int n) {
  return build(0, n);
}

int addtree(int v, int vl, int vr, int l, ll val) {
  if (vr <= l) {
    return v;
  } else if (vl >= l) {
    int res = cntnodes++;
    nodes[res] = node(nodes[v]);
    nodes[res].add(val);
    return res;
  } else {
    int mid = (vl + vr) / 2;
    int a = addtree(nodes[v].l, vl, mid, l, val);
    int b = addtree(nodes[v].r, mid, vr, l, val);
    int res = getnode(a, b);
    nodes[res].add(nodes[v].toadd);
    return res;
  }
}

int addtree(int v, int l, ll val) {
  return addtree(v, 0, n, l, val);
}

ll gettree(int v, int i) {
  int vl = 0, vr = n;
  ll sum = 0;
  while (vl < vr - 1) {
    int mid = (vl + vr) / 2;
    sum += nodes[v].toadd;
    if (mid > i) {
      vr = mid;
      v = nodes[v].l;
    } else {
      vl = mid;
      v = nodes[v].r;
    }
  }
  return sum + nodes[v].mn;
}

int getmnid(int v, int vl, int vr, ll k, ll toadd) {
  if (nodes[v].mn + toadd > k) {
    return inf;
  } else {
    if (vl == vr - 1) {
      return vl;
    } else {
      int mid = (vl + vr) / 2;
      toadd += nodes[v].toadd;
      int res = getmnid(nodes[v].l, vl, mid, k, toadd);
      if (res == inf) {
        res = getmnid(nodes[v].r, mid, vr, k, toadd);
      }
      return res;
    }
  }
}

int getmnid(int v, int k) {
  return getmnid(v, 0, n, k, 0);
}

int mergetree(int v1, int v2, int vl, int vr, int l, ll toadd1, ll toadd2) {
  if (vr <= l) {
    int res = cntnodes++;
    nodes[res] = node(nodes[v1]);
    nodes[res].add(toadd1);
    return res;
  } else if (vl >= l) {
    int res = cntnodes++;
    nodes[res] = node(nodes[v2]);
    nodes[res].add(toadd2);
    return res;
  } else {
    int mid = (vl + vr) / 2;
    toadd1 += nodes[v1].toadd;
    toadd2 += nodes[v2].toadd;
    int res1 = mergetree(nodes[v1].l, nodes[v2].l, vl, mid, l, toadd1, toadd2);
    int res2 = mergetree(nodes[v1].r, nodes[v2].r, mid, vr, l, toadd1, toadd2);
    return getnode(res1, res2);
  }
}

int mergetree(int v1, int v2, int l) {
  return mergetree(v1, v2, 0, n, l, 0, 0);
}

int dp[maxn];

void solve() {
  cntnodes = 0;
  {
    goleft[0] = 0;
    balleft[0] = 0;
    for (int i = 1; i < n; i++) {
      goleft[i] = i - 1;
      balleft[i] = w[i - 1] - g[i];
      while (balleft[i] <= 0 && goleft[i]) {
        balleft[i] += balleft[goleft[i]];
        goleft[i] = goleft[goleft[i]];
      }
    }
  }
  {
    goright[n - 1] = 0;
    balright[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      goright[i] = i + 1;
      balright[i] = w[i] - g[i];
      while (balright[i] <= 0 && goright[i] < n - 1) {
        balright[i] += balright[goright[i]];
        goright[i] = goright[goright[i]];
      }
    }
    dp[0] = 0;
    //eprintf("goright[1] = %d\n", goright[1]);
  }
  {
    stsz = 0;
    int cur = buildzero(n);
    for (int i = 0; i < n; i++) {
      int r = stsz;
      while (stsz && goright[st[stsz - 1]] == i) {
        stsz--;
      }
      int prev = inf;
      for (int j = stsz; j < r; j++) {
        prev = min(prev, dp[st[j]]);
      }
      dp[i] = min(prev, i);
      ll prevval = 0;
      for (int j = stsz; j < r; j++) {
        ll curval = max(0ll, balright[st[j]]);
        cur = addtree(cur, prev, curval - prevval);
        prev = st[j] + 1;
        prevval = curval;
      }
      if (prevval && prev < n) {
        cur = addtree(cur, prev, -prevval);
      }
      val1[i] = cur;
      st[stsz++] = i;
      /*for (int j = 0; j < n; j++) {
        eprintf("%d%c", gettree(val1[i], j), " \n"[j == n - 1]);
      }*/
    }
    val1[n] = val1[n - 1];
  }
  int res = 0;
  {
    val2[0] = val1[1];
    for (int r = 1; r < n; r++) {
      val2[r] = addtree(val2[goleft[r]], 0, balleft[r]);
      {
        int wascnt = cntnodes;
        int L = 0, R = goleft[r] + 1;
        while (L < R) {
          int mid = (L + R) / 2;
          if (gettree(val1[r], mid) < gettree(val2[r], mid)) {
            L = mid + 1;
          } else {
            R = mid;
          }
        }
        //eprintf("L = %d\n", L);
        int tmp = mergetree(val2[r], val1[r], L);
        int curres = getmnid(tmp, k);
        cntnodes = wascnt;
        res = max(res, r - curres + 1);
        /*for (int i = 0; i < n; i++) {
          eprintf("%d%c", gettree(tmp, i), " \n"[i == n - 1]);
        }*/
      }
      {
        int L = 0, R = goleft[r] + 1;
        while (L < R) {
          int mid = (L + R) / 2;
          if (gettree(val1[r + 1], mid) < gettree(val2[r], mid)) {
            L = mid + 1;
          } else {
            R = mid;
          }
        }
        val2[r] = mergetree(val2[r], val1[r + 1], L);
      }
    }
  }
  printf("%d\n", res);
  eprintf("%d\n", cntnodes);
}

int main() {
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