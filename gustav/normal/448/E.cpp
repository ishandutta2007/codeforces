#include <cstdio>
#include <cstring>

#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

typedef long long llint;

#define LIMIT 100005

llint X, k;
int todo = 100000;

map< pair< llint, llint >, pair< int, int > > memo;

vector< llint > f;
vector< llint > sol;

void solve(llint X, llint k, bool prime_hint = 0) {
  if (todo == 0)
    return;

  if (X == 1) {
    sol.push_back(1);
    --todo;
    return;
  }

  if (k == 0) {
    sol.push_back(X);
    --todo;
    return;
  }

  if (memo.count({X, k})) {
    pair< int, int > interval = memo[make_pair(X, k)];
    for (int i = interval.first; i < interval.second && todo > 0; ++i) {
      sol.push_back(sol[i]);
      --todo;
    }
    return;
  }

  vector< llint > tail;
  bool old_hint = prime_hint;

  pair< int, int > interval;
  interval.first = sol.size();

  if (!prime_hint) {
    prime_hint = true;
    llint dX = X;
    for (int I = 0; I < f.size() && f[I] * f[I] <= X && todo > 0; ++I) {
    //for (llint i = 1; i * i <= X && todo > 0; ++i) {
      llint i = f[I];
      if (X % i == 0) {
        if (i != X && i != 1) 
          prime_hint = false;

        solve(i, k - 1, dX % i == 0);

        if (i != X / i)
          tail.push_back(X / i);
        while (dX % i == 0 && i != 1)
          dX /= i;
      }
    }

    if (!prime_hint)
    for (int i = tail.size() - 1; i >= 0 && todo > 0; --i)
      solve(tail[i], k - 1);
  }

  if (prime_hint) {
    for (int i = 0; i < k - (old_hint ^ prime_hint) && todo > 0; ++i) {
      sol.push_back(1);
      --todo;
    }
    if (todo) {
      sol.push_back(X);
      --todo;
    }
  }

  interval.second = sol.size();
  memo[make_pair(X, k)] = interval;
}

int main(void)
{
  cin >> X >> k;

  for (llint i = 1; i * i <= X; ++i) 
    if (X % i == 0) 
      f.push_back(i);

  sort(f.begin(), f.end());
  
  solve(X, k);

  for (int i = 0; i < sol.size(); ++i)
    cout << sol[i] << " ";
  cout << endl;


  return 0;
}