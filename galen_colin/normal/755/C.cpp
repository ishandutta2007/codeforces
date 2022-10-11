// not my code

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define dbg(x) cerr << #x << "->" << x << "\n";
#define prnt(x) cerr<<"{ ";for(auto i:x)cerr<<i<<" ";cerr<<"}\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define pb push_back
const int M = 1000000007;

struct DSU 
{
  vector<int> parent;
  vector<int> sze;
  void build(int n,bool init){
    parent.resize(n,-1);
    sze.resize(n,0);
    if(init){
      for (int i = 0; i < n; i++)
      {
        parent[i] = i;
        sze[i] = 1;
      }
    }
  }
  void make_set(int v)
  {
    parent[v] = v;
    sze[v] = 1;
  }
  int find_set(int v)
  {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_sets(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
      if (sze[a] < sze[b])
        swap(a, b);
      parent[b] = a;
      sze[a] += sze[b];
    }
  }
}dsu;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    dsu.build(n,true);
    for(int i = 0 ; i < n ; i++)
    {
        int u; cin >> u;
        u--;
        if(dsu.find_set(u) != dsu.find_set(i))
        {
            dsu.union_sets(u,i);
        }
    }
    set<int> sets;
    for(auto x : dsu.parent) sets.insert(dsu.find_set(x));
    cout << sets.size();
    return 0;
}