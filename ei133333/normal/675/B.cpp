#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  int64 ret = 0;
  for(int i = 1; i <= N; i++) {
    int64 a = i + A + B;
    int64 b = i + A + C;
    int64 c = i + B + D;
    int64 d = i + C + D;
    auto mx = minmax({a, b, c, d});
    ret += max(N - mx.second + mx.first, 0LL);
  }
  cout << ret << endl;
}