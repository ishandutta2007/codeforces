#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > oio;

pair< int, int > ask(int idx)
{
  cout << "? " << idx + 1 << endl;
  int latte, malta;
  cin >> latte >> malta;
  if(malta == -1) return {latte, malta};
  else return {latte, malta - 1};
};

int main()
{
  std::mt19937 mt((unsigned) time(NULL));

  int N, S, X;
  cin >> N >> S >> X;
  --S;

  for(int i = 0; i < N; i++) oio.insert(i);
  int fact[50000], nxt[50000];
  memset(fact, -1, sizeof(fact));

  set< int > st;
  auto p = ask(S);
  fact[S] = p.first;
  nxt[S] = p.second;
  oio.erase(S);
  oio.erase(p.second);

  for(int i = 0; i < 1500; i++) {
    if(oio.empty()) break;
    auto ptr = *oio.find_by_order(mt() % oio.size());
    auto q = ask(ptr);
    fact[ptr] = q.first;
    nxt[ptr] = q.second;
    oio.erase(ptr);
    oio.erase(q.second);
  }

  int near = -1, now = S;
  for(int i = 0; i < N; i++) {
    if(fact[i] == -1) continue;
    if(fact[i] <= X) {
      if(fact[i] > near) {
        near = fact[i];
        now = i;
      }
    }
  }

  int ret = 1 << 30;
  for(int i = 0; i < 499; i++) {
    if(now == -1) break;
    if(fact[now] == -1) {
      auto q = ask(now);
      fact[now] = q.first;
      nxt[now] = q.second;
    }
    if(fact[now] >= X) ret = min(ret, fact[now]);
    now = nxt[now];
  }
  if(ret >= (1 << 30)) ret = -1;
  cout << "! " << ret << endl;
}