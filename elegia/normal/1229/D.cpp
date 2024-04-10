#include <cstdio>

#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <queue>
#include <vector>
#include <numeric>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef bitset<120> BS;

struct PermHash {
  size_t operator()(const vector<int>& v) const {
    size_t ret = 0;
    for (int x : v)
      ret = ret * 5 + x;
    return ret;
  }
};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<vector<int>> perm;
  unordered_map<vector<int>, int, PermHash> permid;

  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  int fac = 0;
  do {
    perm.push_back(p);
    permid.insert(make_pair(p, fac++));
  } while (next_permutation(p.begin(), p.end()));
  vector<vector<int>> trans(fac, vector<int>(fac));
  for (int i = 0; i < fac; ++i) {
    p = perm[i];
    for (int j = 0; j < fac; ++j) {
      vector<int> q = perm[j], res(k);
      for (int l = 0; l < k; ++l)
        res[l] = p[q[l]];
      trans[i][j] = permid[res];
    }
  }

  BS init = BS();
  init.set(0);

  function<BS(const vector<int>&)> generate = [&](const vector<int>& maj) {
    BS ret = init;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int j = q.front(); q.pop();
      for (int i = 0; i < maj.size(); ++i)
        if (!ret[trans[j][maj[i]]]) {
          ret.set(trans[j][maj[i]]);
          q.push(trans[j][maj[i]]);
        }
    }
    return ret;
  };

  vector<pair<int, int>> vec;
  ll ans = 0;
  while (n--) {
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", &p[i]);
      --p[i];
    }
    int pid = permid[p];
    vector<pair<int, int>> res;
    vector<int> pref;
    pref.push_back(pid);
    BS cb = generate({pid});
    pair<int, int> cur(pid, 1);
    ans += cb.count();
    for (auto& pr : vec) {
      pref.push_back(pr.first);
      BS tmp = generate(pref);
      ans += tmp.count() * pr.second;
      if (tmp == cb) {
        cur.second += pr.second;
      } else {
        res.push_back(cur);
        cur = pr;
        cb = tmp;
      }
    }
    res.push_back(cur);
    vec = res;
  }

  printf("%lld\n", ans);

  return 0;
}