#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1 << 30;

// 


int main() {
  int N, K, L;

  cin >> N >> K >> L;
  multiset< int > st;
  for(int i = 0; i < N * K; i++) {
    int x;
    cin >> x;
    st.emplace(x);
  }

  int small = *st.begin();
  int large = small + L;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    auto it = st.upper_bound(large);
    if(it == st.begin()) {
      cout << 0 << endl;
      return 0;
    }
    --it;
    int rest = K;
    int val = INF;
    while(rest > 0) {
      if(it == st.end()) --it;
      --rest;
      val = min(val, *it);
      it = st.erase(it);
    }
    ret += val;
  }

  cout << ret << endl;
}