#include <bits/stdc++.h>
using namespace std;

void ask(int x, int y)
{
  cout << "? " << x << ' ' << y << endl;
  fflush(stdout);
}

void answer(int x)
{
  cout << "! " << x << endl;
  fflush(stdout);
}

int main()
{
  ios::sync_with_stdio(0);
  string s;
  int low, high, y, phase;
  while (cin >> s)
  {
    if (s == "mistake" || s == "end" || s == "e")
      break;

    if (s == "start")
    {
      // First question
      low = 1;
      phase = 0;
      y = 2;
      ask(0, 2);
      fflush(stdout);
    }
    else if (!phase)
    {
      // Find a good bound
      if (s == "y")
      {
        low = y + 1;
        y = (y + 1) * 2;
        ask(y / 2 - 1, y);
        fflush(stdout);
      }
      else
      {
        high = y;
        phase = 1;
        if (low == 1)
        {
          // special case: a = 1 or a = 2
          ask(0, 1);
          cin >> s;
          answer(s == "x" ? 1 : 2);
        }
        else
        {
          // common case
          ask(low - 1, (low + high) / 2);
        }
      }
    }
    else
    {
      // Binary search
      if (s == "x") high = (low + high) / 2;
      else low = (low + high) / 2 + 1;
      if (low == high) answer(low);
      else ask(low - 1, (low + high) / 2);
    }
  }
}