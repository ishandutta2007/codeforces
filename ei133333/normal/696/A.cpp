#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 Q;
  map< pair< int64, int64 >, int64 > data;
  
  cin >> Q;
  while(Q--) {
    int64 type, v, u, w;
    cin >> type;
    if(type == 1) {
      cin >> v >> u >> w;
      while(v != u) {
        if(u > v) {
          data[{u, u / 2}] += w;
          u /= 2;
        } else {
          data[{v, v / 2}] += w;
          v /= 2;
        }
      }
    } else {
      cin >> v >> u;
      int64 ret = 0;
      while(v != u) {
        if(u > v) {
          ret += data[{u, u / 2}];
          u /= 2;
        } else {
          ret += data[{v, v / 2}];
          v /= 2;
        }
      }
      cout << ret << endl;
    }
  }
  
}