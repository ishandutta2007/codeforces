#include <bits/stdc++.h>

using namespace std;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
  int N;
  cin >> N;
  vector< string > s(N);
  for(auto &c : s) cin >> c;
  sort(begin(s), end(s), [&](string &a, string &b) { return a.size() < b.size(); });
  for(int i = 1; i < s.size(); i++) {
    if(s[i].find(s[i - 1]) == string::npos) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for(auto &c : s) cout << c << endl;

}