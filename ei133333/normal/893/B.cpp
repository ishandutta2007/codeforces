#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int mod = 1e9 + 7;

int main()
{
  int N;
  cin >> N;

  vi divisor;
  for(int i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      divisor.emplace_back(i);
      divisor.emplace_back(N / i);
    }
  }
  sort(divisor.rbegin(), divisor.rend());

  for(auto &p : divisor) {
    int highest = 0;
    for(int i = 0; i < 30; i++) {
      if((p >> i) & 1) highest = i;
    }
    bool flag = false;
    bool ok = true;
    int a = 0, b = 0;
    for(int i = highest; i >= 0; i--) {
      if((p >> i) & 1) {
        if(flag) ok = false;
        ++a;
      } else {
        ++b;
        flag = true;
      }
    }
    if(ok && a - 1 == b) {
      cout << p << endl;
      return(0);
    }
  }
}