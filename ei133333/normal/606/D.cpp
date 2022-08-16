#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;

struct edge {
  int weight, type, idx;
  bool operator<(const edge& e) const {
    if(weight == e.weight) return(type > e.type);
    return(weight < e.weight);
  }
};
int main()
{
  int N, M;
  vector< edge > edges;

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int w, t;
    cin >> w >> t;
    edges.push_back((edge){w, t, i});
  }
  sort(edges.begin(), edges.end());
  vector< Pi > ret(M);
  queue< Pi > Free;
  int used = 2;
  for(int i = 0; i < M; i++) {
    const edge& e = edges[i];
    if(e.type) {
      ret[e.idx] = Pi(1, used);
      for(int j = 2; j < used; j++) {
        if(Free.size() > M) break;
        Free.push(Pi(j, used));
      }
      ++used;
    } else {
      if(Free.empty()) {
        cout << "-1" << endl;
        exit(0);
      } else {
        ret[e.idx] = Free.front(); Free.pop();
      }
    }
  }
  for(int i = 0; i < M; i++) {
    cout << ret[i].first << " " << ret[i].second << endl;
  }
}