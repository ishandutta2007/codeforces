#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

class UnionFind{
private:
  vector< int > rank, p;
  void link(int x,int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{
      p[x] = y;
      if(rank[x] == rank[y]) rank[y]++;
    }
  }
public:
  UnionFind(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i = 0; i < rank.size(); i++){
      p[i] = i, rank[i] = 0;
    }
  }
  void Union(int x,int y){
    link(Find(x),Find(y));
  }
  int Find(int x){
    return( x != p[x] ? p[x] = Find(p[x]) : p[x]);
  }
};

int n, m;

int main(){
  cin >> n >> m;
  vector< UnionFind > ufs;
  for(int i = 0; i < 100; i++){
    ufs.push_back(UnionFind(n));
  }
  for(int i = 0; i < m; i++){
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v, --c;
    ufs[c].Union( u, v);
  }
  int q;
  cin >> q;
  while(q--){
    int a, b;
    cin >> a >> b;
    --a, --b;

    int ret = 0;
    for(int i = 0; i < 100; i++){
      if(ufs[i].Find(a) == ufs[i].Find(b)) ret++;
    }
    cout << ret << endl;
  }
}