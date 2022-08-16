#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 61;

map< int64_t, int > prime_factor(int64_t n)
{
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++){
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return(ret);
}

int main() {
  int64 N, B;
  cin >> N >> B;
  int64 ret = INF;

  for(auto p : prime_factor(B)) {
    int64 c = 0, NN = B;
    NN = N;
    while(NN / p.first > 0) {
      c += NN / p.first;
      NN /= p.first;
    }
    ret = min(ret, c / p.second);
  }
  cout << ret << endl;
}