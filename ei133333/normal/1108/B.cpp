#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  multiset< int > mp;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    mp.emplace(x);
  }
  auto x = *prev(mp.end());
  for(int i = 1; i <= x; i++) {
    if(x % i == 0) {
      mp.erase(mp.find(i));
    }
  }
  cout << x << " " << *prev(mp.end()) << endl;
}