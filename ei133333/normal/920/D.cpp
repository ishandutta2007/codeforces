#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, K, V, A[5000];
bool v[5001];
vector< int > used;
bool visited[5000][5001];

int rec(int idx, int mod)
{
  if(mod == V % K) return (true);
  if(idx == N) return (false);
  if(visited[idx][mod]++) return (false);
  if(rec(idx + 1, mod)) return (true);
  if(rec(idx + 1, (mod + A[idx]) % K)) {
    used.push_back(idx);
    v[idx] = true;
    return (true);
  }
  return (false);
}

int main()
{
  cin >> N >> K >> V;
  bool found = false;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  if(rec(0, 0)) {
    vector< int > unused;
    for(int i = 0; i < N; i++) {
      if(!v[i]) unused.emplace_back(i);
    }

    vector< tuple< int, int, int > > order;
    int latte = 0, malta = 0;
    for(int i : used) latte += A[i];
    for(int i : unused) malta += A[i];

    for(int i = 1; i < used.size(); i++) {
      order.emplace_back(used[i], used[0], 1000000000);
    }
    for(int i = 1; i < unused.size(); i++) {
      order.emplace_back(unused[i], unused[0], 1000000000);
    }
    malta = malta / K * K;
    if(malta > 0) {
      order.emplace_back(unused[0], used.size() ? used[0] : 0, malta / K);
      latte += malta;
    }
    if(latte < V) {
      cout << "NO" << endl;
      return (0);
    }
    if(V % K == 0) order.emplace_back(0, 1, V / K);
    else order.emplace_back(used[0], used[0] == 0, (latte - V) / K);
    cout << "YES" << endl;
    for(auto &p : order) {
      int x, y, z;
      tie(x, y, z) = p;
      if(z) cout << z << " " << x + 1 << " " << y + 1 << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}