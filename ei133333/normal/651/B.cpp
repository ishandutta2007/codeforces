#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, A[1000];
  cin >> N;
  multiset< int > vv;
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    vv.insert(K);
  }
  int ret = 0, now = *vv.begin();
  vv.erase(vv.begin());
  while(!vv.empty()) {
    bool f = false;
    for(auto v : vv) {
      if(now < v) {
        now = v;
        vv.erase(vv.find(v));
        ++ret;
        f = true;
        break;
      }
    }
    if(!f) {
      now = *vv.begin();
      vv.erase(vv.begin());
    }
  }
  cout << ret << endl;
}