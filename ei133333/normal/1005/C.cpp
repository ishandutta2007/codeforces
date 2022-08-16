#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

int main() {

  int64 N, A[120000];
  cin >> N;
  map< int64, int > mp;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }
  int ret = 0;
  for(int i = 0; i < N; i++) {
    bool flag = false;
    mp[A[i]]--;
    for(int64 j = 1LL; j < (1LL << 33); j <<= 1LL) {
      int64 rest = j - A[i];
      if(mp.count(rest) && mp[rest] >= 1) {
        flag = true;
        break;
      }
    }
    mp[A[i]]++;
    if(!flag) ++ret;
  }
  cout << ret << endl;
}