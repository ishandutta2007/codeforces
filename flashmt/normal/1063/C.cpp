#include <bits/stdc++.h>
using namespace std;

int ask(int x)
{
  cout << x << ' ' << 1 << endl;
  cout.flush();
  string s;
  cin >> s;
  return s == "black";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, low = 0, high = 1e9;
  cin >> n;
  int initialColor = ask(0);
  for (int i = 1; i < n; i++)
  {
    int mid = (low + high) / 2;
    int color = ask(mid);
    if (color == initialColor) low = mid;
    else high = mid;
  }

  cout << low << ' ' << 0 << ' ' << high << ' ' << 2 << endl;
}