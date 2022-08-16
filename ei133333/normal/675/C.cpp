#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;
int main()
{
  int N;
  cin >> N;
  int64 sum = 0;
  map< int64, int > mp;
  for(int i = 0; i < N; i++) {
    int D;
    cin >> D;
    sum += D;
    ++mp[sum];
  }
  int ret = INF;
  for(auto k : mp) {
    ret = min(ret, N - k.second);
  }
  cout << ret << endl;
}