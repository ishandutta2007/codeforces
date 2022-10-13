#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long c[100100], t[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  vector<int> difC, difT;
  for (int i = 1; i < n; i++)
  {
    difC.push_back(c[i] - c[i - 1]);
    difT.push_back(t[i] - t[i - 1]);
  }
  sort(difC.begin(), difC.end());
  sort(difT.begin(), difT.end());

  cout << (c[0] == t[0] && c[n - 1] == t[n - 1] && difC == difT ? "Yes" : "No") << endl;
}