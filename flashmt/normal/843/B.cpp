#include <bits/stdc++.h>
using namespace std;
#define next _next
const int K = 1000;

int n, start, x, v[50500], next[50500];
vector< pair<int, int> > known;

void ask(int i)
{
  cout << "? " << i << endl;
  fflush(stdout);
  cin >> v[i] >> next[i];
  known.push_back({v[i], i});
}

void answer(int ans)
{
  cout << "! " << ans << endl;
  fflush(stdout);
  exit(0);
}

void solve(int i, int curAns)
{
  for (int turn = 0; turn < 1999 - K; turn++)
  {
    i = next[i];
    if (i < 0)
      answer(-1);
    ask(i);
    if (v[i] >= x)
      answer(v[i]);
  }
  answer(curAns);
}

int myRand()
{
  int res = 0;
  for (int i = 0; i < 20; i++)
    if (rand() % 2) res |= 1 << i;
  return res;
}

int main()
{
  srand(time(NULL));
  cin >> n >> start >> x;
  ask(start);
  if (v[start] >= x) 
    answer(v[start]);

  for (int turn = 0; turn < K - 1; turn++)
    ask(myRand() % n + 1);
  sort(known.begin(), known.end());

  int curAns = -1;
  for (int i = K - 1; i >= 0; i--)
    if (known[i].first < x) solve(known[i].second, curAns);
    else curAns = known[i].first;
}