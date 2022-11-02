#include <bits/stdc++.h>
using namespace std;
#define prev qwqwqwqwqwqwq
#define next pwpwpwpwpwpwp
typedef signed long long int LL;
typedef pair<int, int> pii;

const int maxN = 100000 + 233;
int n, m, a[maxN];
set<int> S[maxN];

bool isq[maxN];
LL ans[maxN];
struct Entry {
  int time, type; // 0 for ele's, 1 for q's
  int sub, pos;
  int coef; // for q's only
  Entry(int a, int b, int c, int d, int e) :
    time(a), type(b), sub(c), pos(d), coef(e) {}
  Entry() {}
};

vector<Entry> prev, next, tmp;

pii get(int x) {
  auto ptr = S[a[x]].find(x);
  auto i = ptr;
  int pre = (i == S[a[x]].begin() ? 0 : *(--i));
  i = ptr;
  int post = (++i == S[a[x]].end() ? n + 1 : *i);
  return pii(pre, post);
}

LL C[maxN];
void add(int p, LL x) {
  for(int i = p + 2; i <= n + 10; i += i & -i) C[i] += x;
}
LL sum(int p) {
  LL r = 0;
  for(int i = p + 2; i > 0; i -= i & -i) r += C[i];
  return r;
}

void solve(int L, int R) {
  if(L >= R) return;
  int M = (L + R) >> 1;
  solve(L, M); solve(M + 1, R);
  int i = L, j = M + 1;
  int pp = L;
  auto Left = [&](Entry e) {
    if(e.type == 0) add(e.pos, e.pos * e.coef);
    tmp[pp++] = e;
  };
  auto Right = [&](Entry e) {
    if(e.type == 1) ans[e.time] += e.coef * sum(e.pos);
    tmp[pp++] = e;
  };
  while(i <= M && j <= R) {
    if(next[i].sub <= next[j].sub) Left(next[i++]);
    else Right(next[j++]);
  }
  while(i <= M) Left(next[i++]);
  while(j <= R) Right(next[j++]);
  assert(pp == R + 1);
  for(int k = L; k <= M; ++k) if(next[k].type == 0) {
    add(next[k].pos, - next[k].pos * next[k].coef);
  }
  for(int k = L; k <= R; ++k) next[k] = tmp[k];
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    S[a[i]].insert(i);
  }
  for(int i = 1; i <= n; ++i) {
    pii p = get(i);
    prev.emplace_back(0, 0, p.first, i, 1);
    next.emplace_back(0, 0, p.second, i, 1);
  }
  memset(ans, 0, sizeof(ans));
  for(int i = 1; i <= m; ++i) {
    int op, x, y; cin >> op >> x >> y;
    if(op == 1) {
      isq[i] = false;
      pii p = get(x);
      if(p.first >= 1) {
        next.emplace_back(i, 0, x, p.first, -1);
        next.emplace_back(i, 0, p.second, p.first, 1);
      }
      if(p.second <= n) {
        prev.emplace_back(i, 0, x, p.second, -1);
        prev.emplace_back(i, 0, p.first, p.second, 1);
      }
      next.emplace_back(i, 0, p.second, x, -1);
      prev.emplace_back(i, 0, p.first, x, -1);

      S[a[x]].erase(x); S[y].insert(x); a[x] = y;
      p = get(x);
      if(p.first >= 1) {
        next.emplace_back(i, 0, x, p.first, 1);
        next.emplace_back(i, 0, p.second, p.first, -1);
      }
      if(p.second <= n) {
        prev.emplace_back(i, 0, x, p.second, 1);
        prev.emplace_back(i, 0, p.first, p.second, -1);
      }
      next.emplace_back(i, 0, p.second, x, 1);
      prev.emplace_back(i, 0, p.first, x, 1);
    } else if(op == 2) {
      isq[i] = true;
      next.emplace_back(i, 1, y, y, -1);
      next.emplace_back(i, 1, y, x - 1, 1);
      prev.emplace_back(i, 1, x, y, 1);
      prev.emplace_back(i, 1, x, x - 1, -1);
    } else {
      assert(false);
    }
  }
  tmp.resize(max(prev.size(), next.size()));
  std::sort(next.begin(), next.end(), [](Entry A, Entry B) {
    return A.time != B.time ? A.time < B.time :
      A.sub != B.sub ? A.sub < B.sub :
      A.pos < B.pos;
  });
  solve(0, (int)next.size() - 1);

  for(auto &e : prev) e.sub = n + 1 - e.sub;
  next.swap(prev);
  std::sort(next.begin(), next.end(), [](Entry A, Entry B) {
    return A.time != B.time ? A.time < B.time :
      A.sub != B.sub ? A.sub < B.sub :
      A.pos < B.pos;
  });
  solve(0, (int)next.size() - 1);

  for(int i = 1; i <= m; ++i) if(isq[i]) printf("%lld\n", ans[i]);
  return 0;
}