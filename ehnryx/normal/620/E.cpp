#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;
int colour[N], start[N], sz[N];
vector<int> adj[N];

int sid = 0;
void build(int u, int p) {
  if(p) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
  start[u] = sid++;
  sz[u] = 1;
  for(int v : adj[u]) {
    build(v, u);
    sz[u] += sz[v];
  }
}

long long st[2*N], z[2*N];

void push(int i) {
  if(z[i]) {
    st[2*i] = st[2*i+1] = z[2*i] = z[2*i+1] = z[i];
    z[i] = 0;
  }
}

void pull(int i) {
  st[i] = st[2*i] | st[2*i+1];
}

void insert(int l, int r, long long v, int i=1, int s=0, int e=N-1) {
  if(r<s || e<l) return;
  if(l<=s && e<=r) {
    st[i] = z[i] = v;
    return;
  }
  push(i);
  int m = (s+e)/2;
  insert(l, r, v, 2*i, s, m);
  insert(l, r, v, 2*i+1, m+1, e);
  pull(i);
}

long long query(int l, int r, int i=1, int s=0, int e=N-1) {
  if(r<s || e<l) return 0;
  if(l<=s && e<=r) return st[i];
  push(i);
  int m = (s+e)/2;
  return query(l, r, 2*i, s, m) | query(l, r, 2*i+1, m+1, e);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> colour[i];
  }
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  build(1, 0);

  for(int i=1; i<=n; i++) {
    insert(start[i], start[i], 1LL << colour[i]);
  }

  for(int i=0; i<m; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int v, c;
      cin >> v >> c;
      insert(start[v], start[v] + sz[v] - 1, 1LL << c);
    } else {
      int v;
      cin >> v;
      cout << __builtin_popcountll(query(start[v], start[v] + sz[v] - 1)) << '\n';
    }
  }

  return 0;
}