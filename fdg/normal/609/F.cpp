#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>

using namespace std;

struct frog {
  long long l, r, id;
};

bool operator < (const frog& a, const frog& b) {
  return a.r < b.r;
}

long long cnt[200005], len[200005];
set<frog> frogs;
multiset<pair<int, int>> mosquitoes;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < n; ++i) {
    int x, t;
    scanf("%d%d", &x, &t);
    v.push_back({x, {t, i}});
  }
  sort(v.begin(), v.end());
  
  int last = -1;
  for (int i = 0; i < n; ++i) {
    int l = v[i].first, r = v[i].first + v[i].second.first;
    if (last < r) {
      frogs.insert({l, r, v[i].second.second});
      last = r;
      // cout << l << "  " << r << " " << v[i].second.second << endl;
    }
    len[v[i].second.second] += v[i].second.first;
  }

  for (int i = 0; i < m; ++i) {
    int p, s;
    scanf("%d%d", &p, &s);

    set<frog>::iterator it = frogs.lower_bound({-1, p, p}), tmp, tmp2;
    if (it != frogs.end()) {
      if (it->l <= p && p <= it->l + len[it->id]) {
        // cout << it->id << " " << p << " " << s << endl;
        cnt[it->id]++;
        len[it->id] += s;

        multiset<pair<int, int>>::iterator m_it = mosquitoes.lower_bound({it->l, -1}), m_tmp;
        while (m_it != mosquitoes.end()) {
          m_tmp = m_it; ++m_tmp;
          // cout << "Who: " << m_it->first << "  " << it->l + len[it->id] << endl;
          if (m_it->first <= it->l + len[it->id]) {
            cnt[it->id]++;
            len[it->id] += m_it->second;
            mosquitoes.erase(m_it);
            m_it = m_tmp;
          } else {
            break;
          }
        }

        tmp = it; ++tmp;
        while (tmp != frogs.end()) {
          tmp2 = tmp; ++tmp2;
          if (tmp->r <= it->l + len[it->id]) {
            frogs.erase(tmp);
            tmp = tmp2;
          } else {
            break;
          }
        }
        frog curFrog = *it;
        curFrog.r = it->l + len[it->id];
        frogs.erase(it);
        frogs.insert(curFrog);
      } else {
        mosquitoes.insert({p, s});
      }
    } else {
      mosquitoes.insert({p, s});
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld %lld\n", cnt[i], len[i]);
  }
  return 0;
}