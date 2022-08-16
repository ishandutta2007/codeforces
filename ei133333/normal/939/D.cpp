#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    //  if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};


int main()
{
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;

  vector< pair< char, char > > es;
  int g[26] = {};
  for(int i = 0; i < N; i++) {
    if(S[i] != T[i]) g[S[i] - 'a'] |= 1 << (T[i] - 'a');
  }
  for(int i = 0; i < 26; i++) {
    g[i] |= 1 << i;
  }

  bool update = true;
  UnionFind uf(26);

  while(update) {
    update = false;
    int pop_count = 0;
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) {
        if(uf.find(i) == uf.find(j)) continue;
        if(uf.find(i) != i) continue;
        if(uf.find(j) != j) continue;
        if((g[i] & g[j]) == 0) continue;

        pop_count = max(pop_count, __builtin_popcount(g[i] & g[j]));
      }
    }

    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) {
        if(uf.find(i) == uf.find(j)) continue;
        if(uf.find(i) != i) continue;
        if(uf.find(j) != j) continue;
        if((g[i] & g[j]) == 0) continue;
        if(pop_count == __builtin_popcount(g[i] & g[j])) {
          es.emplace_back(j + 'a', i + 'a');
          uf.unite(j, i);
          int next = g[i] | g[j];
          g[i] = g[j] = next;
          update = true;
          goto latte;
        }
      }
    }
    latte:;
  }

  cout << es.size() << endl;
  for(auto &p : es) cout << p.first << " " << p.second << endl;

}