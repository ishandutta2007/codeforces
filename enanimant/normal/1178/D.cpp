// July 20, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAX = 5000;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  vector<int> p(MAX, 0);
  for (int i = 2; i * i < MAX; i++) {
    if (p[i] != 0) {
      continue;
    }
    for (int j = i * i; j < MAX; j += i) {
      p[j] = i;
    }
  }

  // for (int n = 3; n <= 1000; n++) {
  //   if (upper_bound(primes.begin(), primes.end(), n + n / 2) == lower_bound(primes.begin(), primes.end(), n)) {
  //     cerr << n << " failed\n";
  //   }
  // }

  int N;
  cin >> N;
  vector<int> deg(N, 2);
  vector< pair<int, int> > edges;
  for (int i = 0; i < N; i++) {
    edges.push_back({i, (i + 1) % N});
  }
  int a = 0;
  while (p[edges.size()] != 0) {
    edges.push_back({a, a + (N + 1) / 2});
    a++;
  }
  cout << edges.size() << '\n';
  for (auto p : edges) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }


  return 0;
}