#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 xor128() {
  static int x = 123456789;
  static int y = 362436069;
  static int z = 521288629;
  static int w = 88675123;
  int t;

  t = x ^ (x << 11);
  x = y;
  y = z;
  z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}


bool check1(int v) {
  cout << "> " << v << endl;
  int k;
  cin >> k;
  return k == 0;
}

int main() {
  int N;
  cin >> N;

  int ng = 0, ok = 1000000000;
  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check1(mid)) ok = mid;
    else ng = mid;
  }

  random_device rnd;

  vector< int > vs;
  for(int i = 0; i < 29; i++) {
    cout << "? " << 1 + (xor128() * xor128() % N * xor128()) % N << endl;
    int k;
    cin >> k;
    vs.emplace_back(k);
  }
  vs.emplace_back(ok);
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));

  int gcd = 0;
  for(int i = 0; i + 1 < vs.size(); i++) {
    gcd = __gcd(gcd, vs[i + 1] - vs[i]);
  }
  cout << "! " << vs.back() - gcd * (N - 1) << " " << gcd << endl;
}