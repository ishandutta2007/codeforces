#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int MOD = 998244353;
using i64 = long long;
class SegmentTree
{
private:
  int n;
  vector<long long> data;
  vector<long long> mulDelay;
  vector<long long> addDelay;
  void updateTree(int a, int b, int k, int l, int r, long long mulNum, long long addNum){
    if(a <= l && r <= b){
      data[k] *= mulNum;
      data[k] += addNum * (r - l + 1);
      data[k] %= MOD;
      mulDelay[k] *= mulNum;
      mulDelay[k] %= MOD;
      addDelay[k] *= mulNum;
      addDelay[k] += addNum;
      addDelay[k] %= MOD;
    }
    else if(a <= r && l <= b){
      for(int i=0; i<2; ++i){
        data[k*2+1+i] *= mulDelay[k];
        data[k*2+1+i] += addDelay[k] * (r - l + 1) / 2;
        data[k*2+1+i] %= MOD;
        mulDelay[k*2+1+i] *= mulDelay[k];
        mulDelay[k*2+1+i] %= MOD;
        addDelay[k*2+1+i] *= mulDelay[k];
        addDelay[k*2+1+i] += addDelay[k];
        addDelay[k*2+1+i] %= MOD;
      }
      mulDelay[k] = 1;
      addDelay[k] = 0;
      updateTree(a, b, k*2+1, l, (l+r)/2, mulNum, addNum);
      updateTree(a, b, k*2+2, (l+r+1)/2, r, mulNum, addNum);
      data[k] = data[k*2+1] + data[k*2+2];
      data[k] %= MOD;
    }
  }
  long long getValue(int a, int b, int k, int l, int r){
    long long ret = 0;
    if(a <= l && r <= b){
      return data[k];
    }else if(a <= r && l <= b){
      for(int i=0; i<2; ++i){
        data[k*2+1+i] *= mulDelay[k];
        data[k*2+1+i] += addDelay[k] * (r - l + 1) / 2;
        data[k*2+1+i] %= MOD;
        mulDelay[k*2+1+i] *= mulDelay[k];
        mulDelay[k*2+1+i] %= MOD;
        addDelay[k*2+1+i] *= mulDelay[k];
        addDelay[k*2+1+i] += addDelay[k];
        addDelay[k*2+1+i] %= MOD;
      }
      mulDelay[k] = 1;
      addDelay[k] = 0;
      ret += getValue(a, b, k*2+1, l, (l+r)/2);
      ret += getValue(a, b, k*2+2, (l+r+1)/2, r);
      ret %= MOD;
    }
    return ret;
  }
public:
  SegmentTree(int n0){
    n = 1;
    while(n < n0)
      n *= 2;
    data.assign(2*n-1, 0);
    mulDelay.assign(2*n-1, 1);
    addDelay.assign(2*n-1, 0);
  }
  void set(int a, int b, long long x){ // [a,b]x
    --b;
    updateTree(a, b, 0, 0, n-1, 0, x);
  }
  void add(int a, int b, long long x){ // [a,b]x
    --b;
    updateTree(a, b, 0, 0, n-1, 1, x);
  }
  void mul(int a, int b, long long x){ // [a,b]x
    --b;
    updateTree(a, b, 0, 0, n-1, x, 0);
  }
  long long get(int a, int b){         // [a,b]
    --b;
    return getValue(a, b, 0, 0, n-1);
  }
};


int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  set< pair< int, int > > stock[200001];
  for(int i = 0; i < 200001; i++) stock[i].emplace(-2, -1);
  SegmentTree seg(N);


  while(Q--) {
    int k;
    scanf("%d", &k);
    if(k == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", seg.get(l - 1, r));
    } else {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      --l;

      int reached = r;
      vector< pair< int, int > > done;

      done.emplace_back(l, l);
      auto it = stock[x].lower_bound({l, -1});
      --it;
      if(it->second >= r) {
        seg.mul(l, r, 2);
        done.emplace_back(it->first, min(r, it->second));
        continue;
      }
      int prevreached = l;
      if(it->second > l) {
        seg.mul(l, it->second, 2);
        done.emplace_back(l, it->second);
        prevreached = min(prevreached, it->first);
        it = stock[x].erase(it);
      } else {
        ++it;
      }

      while(it != stock[x].end() && it->first < r) {
        seg.mul(it->first, min(r, it->second), 2);
        done.emplace_back(it->first, min(r, it->second));
        reached = max(reached, it->second);
        it = stock[x].erase(it);
      }
      it = stock[x].lower_bound({l, -1});
      done.emplace_back(r, r);
      for(int i = 1; i < done.size(); i++) {
        seg.add(done[i - 1].second, done[i].first, 1);
      }
      stock[x].emplace(prevreached, reached);
    }
  }

}