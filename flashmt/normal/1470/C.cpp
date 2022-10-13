#include <bits/stdc++.h>
using namespace std;
const int K = 330;

int ask(int x)
{
  cout << "? " << x + 1 << endl;
  cout.flush();
  int res;
  cin >> res;
  return res;
}

void answer(int x)
{
  cout << "! " << x + 1 << endl;
  cout.flush();
  exit(0);
}

int main()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < K; i++)
    ask(0);

  int step = max(1, n / K), ranges = (n + step - 1) / step;
  vector<int> resp;
  for (int i = 0; i < ranges; i++)
    resp.push_back(ask(i * step));

  for (int i = 0; i < ranges; i++)
  {
    int ii = (i + 1) % ranges;
    if (resp[ii] > resp[i])
    {
      int id = i * step, prev = ask(id);
      int cntGreater = ask((id + n - 1) % n) < prev;
      for (int j = 1; j <= step + 2; j++)
      {
        int cur = ask((id + j) % n);
        if (cur > prev) cntGreater++;
        else cntGreater = 0;
        if (cntGreater == 2)
          answer((id + j + n - 1) % n);
        prev = cur;
      }
      assert(0);
    }
  }

  assert(0);
}