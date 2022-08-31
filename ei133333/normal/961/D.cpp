#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N;
  int64 X[100000], Y[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  if(N <= 2) {
    cout << "YES" << endl;
    return (0);
  }

  auto is_one_line = [&](int a, int b, int c) {
    int64 bx = X[b] - X[a], by = Y[b] - Y[a];
    int64 cx = X[c] - X[a], cy = Y[c] - Y[a];
    return (bx * cy - by * cx == 0);
  };


  bool v[100000] = {};
  for(int i = 1; i < N; i++) {
    if(is_one_line(0, 1, i)) v[i] = true;
  }
  vector< int > another;
  for(int i = 2; i < N; i++) {
    if(!v[i]) another.emplace_back(i);
  }
  bool ok = true;
  for(int i = 2; i < another.size(); i++) {
    if(!is_one_line(another[0], another[1], another[i])) ok = false;
  }
  if(ok) {
    cout << "YES" << endl;
    return (0);
  }

  int root = 1;
  for(int i = 2; i < N; i++) {
    if(!v[i]) root = i;
  }
  memset(v, 0, sizeof(v));
  another.clear();
  for(int i = 1; i < N; i++) {
    if(is_one_line(0, root, i)) {
      v[i] = true;
    }
  }
  for(int i = 1; i < N; i++) {
    if(!v[i]) another.emplace_back(i);
  }
  ok = true;
  for(int i = 2; i < another.size(); i++) {
    if(!is_one_line(another[0], another[1], another[i])) ok = false;
  }
  if(ok) {
    cout << "YES" << endl;
    return (0);
  }



  // root-1-
  memset(v, 0, sizeof(v));
  another.clear();
  for(int i = 0; i < N; i++) {
    if(is_one_line(1, root, i)) {
      v[i] = true;
    }
  }
  for(int i = 0; i < N; i++) {
    if(!v[i]) another.emplace_back(i);
  }
  ok = true;
  for(int i = 2; i < another.size(); i++) {
    if(!is_one_line(another[0], another[1], another[i])) ok = false;
  }
  if(ok) {
    cout << "YES" << endl;
    return (0);
  }


  cout << "NO" << endl;
}