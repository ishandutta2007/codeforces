#include <bits/stdc++.h>

using namespace std;

struct StronglyConnectedComponents
{
  vector< vector< int > > gg, rg;
  vector< pair< int, int > > edges;
  vector< int > comp, order, used;

  StronglyConnectedComponents(size_t v) : gg(v), rg(v), comp(v, -1), used(v, 0) {}

  void add_edge(int x, int y)
  {
    gg[x].push_back(y);
    rg[y].push_back(x);
    edges.emplace_back(x, y);
  }

  int operator[](int k)
  {
    return (comp[k]);
  }

  void dfs(int idx)
  {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt)
  {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector< vector< int > > &t)
  {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    set< pair< int, int > > connect;
    for(auto &e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      if(connect.count({x, y})) continue;
      t[x].push_back(y);
      connect.emplace(x, y);
    }
  }
};

string A, V;
vector< int > g[400];
int N, M;

void rrec(int idx, bool ue, string value)
{
  if(idx == A.size()) {
    cout << value << endl;
    exit(0);
  }

  char begin = (ue ? 'a' : A[idx]) - 'a';
  bool isbeet = false, ishihu = false;
  for(int i = begin; i < V.size(); i++) {

    if(isbeet && ishihu) break;

    if(V[i] == 'C') {
      if(isbeet) continue;
      if(value[idx] == 'V') continue;
      string next = value;
      if(isalpha(value[idx])) {
        isbeet |= ue | (i != begin);
        next[idx] = (char) (i + 'a');
        rrec(idx + 1, ue | (i != begin), next);
      } else {
        bool isei = true;
        queue< int > q;
        q.push(idx);
        while(!q.empty()) {
          int p = q.front();
          q.pop();
          char cc = p < N ? 'C' : 'V';
          if(next[p % N] != ' ') {
            if(islower(next[p % N]) && V[next[p % N] - 'a'] != cc) {
              isei = false;
              break;
            } else if(isupper(next[p % N]) && next[p % N] != cc) {
              isei = false;
              break;
            }
          }
          if(next[p % N] != ' ') continue;
          next[p % N] = cc;
          for(auto &s : g[p]) if(next[s % N] != (s < N ? 'C' : 'V')) q.push(s);
        }
        if(isei) {
          next[idx] = (char) (i + 'a');
          rrec(idx + 1, ue | (i != begin), next);
        }
        isbeet |= ue | (i != begin);
      }

    } else {
      if(ishihu) continue;
      if(value[idx] == 'C') continue;
      string next = value;

      if(isalpha(value[idx])) {
        ishihu |= ue | (i != begin);
        next[idx] = (char) (i + 'a');
        rrec(idx + 1, ue | (i != begin), next);
      } else {
        bool isei = true;
        queue< int > q;
        q.push(idx + N);
        while(!q.empty()) {
          int p = q.front();
          q.pop();
          char cc = p < N ? 'C' : 'V';
          if(next[p % N] != ' ') {
            if(islower(next[p % N]) && V[next[p % N] - 'a'] != cc) {
              isei = false;
              break;
            } else if(isupper(next[p % N]) && next[p % N] != cc) {
              isei = false;
              break;
            }
          }
          if(next[p % N] != ' ') continue;
          next[p % N] = cc;
          for(auto &s : g[p]) if(next[s % N] != (s < N ? 'C' : 'V')) q.push(s);
        }
        if(isei) {
          next[idx] = (char) (i + 'a');
          rrec(idx + 1, ue | (i != begin), next);
        }
        ishihu |= ue | (i != begin);
      }
    }
  }
}


int main()
{
  cin >> V;
  cin >> N >> M;
  StronglyConnectedComponents scc(N * 2);
  for(int i = 0; i < M; i++) {
    int a, b;
    char c, d;
    cin >> a >> c >> b >> d;
    --a, --b;
    if(c == 'V') a += N;
    if(d == 'V') b += N;
    g[a].push_back(b);
    scc.add_edge(a, b);
  }
  vector< vector< int > > g;
  scc.build(g);
  for(int i = 0; i < N; i++) {
    if(scc[i] == scc[i + N]) {
      cout << -1 << endl;
      return (0);
    }
  }
  
  cin >> A;
  rrec(0, 0, string(A.size(), ' '));
  cout << -1 << endl;
}