#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector< int > vs(N);
  bool zero = false;
  for(int i = 0; i < N; i++) {
    cin >> vs[i];
    if(vs[i] == 0) zero = true;
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  cout << vs.size() - zero << endl;
}