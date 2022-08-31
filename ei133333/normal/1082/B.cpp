#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  int all = 0;
  for(auto &c : S) all += c == 'G';

  int pending = 0;
  vector< int > uku;
  for(auto &c : S) {
    if(c == 'G') {
      ++pending;
    } else {
      pending = 0;
    }
    uku.push_back(pending);
  }

  pending = 0;
  reverse(begin(S), end(S));
  vector< int > uku2;
  for(auto &c : S) {
    if(c == 'G') {
      ++pending;
    } else {
      pending = 0;
    }
    uku2.push_back(pending);
  }
  reverse(begin(S), end(S));
  reverse(begin(uku2), end(uku2));

  int ret = *max_element(begin(uku), end(uku));
  for(int i = 1; i + 1 < N; i++) {
    if(S[i] == 'S') {
      ret = max(ret, uku[i - 1] + uku2[i + 1]);
    }
  }
  cout << min(all, ret + 1) << endl;
}