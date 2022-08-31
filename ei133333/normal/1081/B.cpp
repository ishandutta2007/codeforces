#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector< int > kinds[100001];
  for(int i = 0; i < N; i++) {
    kinds[N - A[i]].emplace_back(i);
  }

  int ptr = 1;
  vector< int > ans(N);
  for(int i = 1; i <= N; i++) {
    if(kinds[i].size() % i != 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    while(kinds[i].size()) {
      if(ptr > N) {
        cout << "Impossible" << endl;
        return 0;
      }
      for(int j = 0; j < i; j++) {
        ans[kinds[i].back()] = ptr;
        kinds[i].pop_back();
      }
      ++ptr;
    }
  }
  cout << "Possible\n";
  for(auto& c : ans) cout << c << " ";
  cout << endl;
}