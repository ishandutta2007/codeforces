#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 K;
  int A, B;
  int U[3][3], V[3][3];

  cin >> K >> A >> B;
  --A, --B;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> U[i][j];
      --U[i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> V[i][j];
      --V[i][j];
    }
  }

  auto judge = [](int a, int b)
  {
    if(a == b) return make_pair(0, 0);
    if(a == 2 && b == 1) return make_pair(1, 0);
    if(a == 1 && b == 0) return make_pair(1, 0);
    if(a == 0 && b == 2) return make_pair(1, 0);
    return make_pair(0, 1);
  };

  map< pair< int, int >, pair< int, int > > visited;
  map< pair< int, int >, int > happened;

  int ptr = 0;
  pair< int64, int64 > now(0LL, 0LL);
  while(!visited.count({A, B}) && K > 0) {
    auto p = judge(A, B);
    visited[{A, B}] = now;
    happened[{A, B}] = ptr++;
    now.first += p.first, now.second += p.second;
    int X = U[A][B], Y = V[A][B];
    A = X, B = Y;
    --K;
  }

  if(K > 0) {
    int64 delta1 = now.first - visited[{A, B}].first;
    int64 delta2 = now.second - visited[{A, B}].second;
    int64 loop_length = ptr - happened[{A, B}];

    now.first += delta1 * (K / loop_length);
    now.second += delta2 * (K / loop_length);
    K %= loop_length;

    while(K > 0) {
      auto p = judge(A, B);
      now.first += p.first, now.second += p.second;
      int X = U[A][B], Y = V[A][B];
      A = X, B = Y;
      --K;
    }
  }

  cout << now.first << " " << now.second << endl;
}