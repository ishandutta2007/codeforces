#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector< pair< int, int > > tap;
int N, K;

void add1() {
  int p = 0, q = 1, used = 2;
  while(tap.size() < K && (!(p == 0 && q == N - 1))) {
    tap.emplace_back(p, q);
    ++p;
    ++q;
    if(q >= N) {
      p = 0;
      q = used++;
    }
  }
}

void add2() {
  int p = N - 1, q = N - 2, used = N - 3;
  while(tap.size() < K && (!(p == N - 1 && q == 0))) {
    tap.emplace_back(p, q);
    --p;
    --q;
    if(q < 0) {
      p = N - 1;
      q = used--;
    }
  }
}

int main() {
  cin >> K >> N;
  if(tap.size() < K) tap.emplace_back(N - 1, 0);
  add1();
  add2();
  if(tap.size() < K) tap.emplace_back(0, N - 1);

  if(tap.size() < K) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for(auto x : tap) {
      cout << x.first+1 << " " << x.second+1 << endl;
    }
  }
}