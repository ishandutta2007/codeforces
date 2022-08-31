#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int64 N, X[100000];

int main() {
  cin >> N;
  for(int i = 1; i < N; i += 2) {
    cin >> X[i];
  }
  int64 cur_sum = 0;

  vector< int64 > xs;
  unordered_set< int64 > its;
  const int64 LIM = 10000000000000LL;
  for(int64 i = 1; i * i <= LIM; i++) {
    xs.emplace_back(i * i);
    its.emplace(i * i);
  }
  int ptr = 0;
  for(int i = 0; i < N; i += 2) {
    while(ptr < xs.size() && xs[ptr] <= cur_sum) {
      ++ptr;
    }
    while(ptr < xs.size() && !its.count(cur_sum + (xs[ptr] - cur_sum) + X[i + 1])) {
      ++ptr;
    }
    if(ptr >= xs.size()) {
      cout << "No\n";
      return 0;
    }
    X[i] = (xs[ptr] - cur_sum);
    cur_sum += xs[ptr] - cur_sum;
    cur_sum += X[i+1];
  }
  cout << "Yes\n";
  for(int i = 0; i < N; i++) cout << X[i] << " ";
  cout << endl;
}