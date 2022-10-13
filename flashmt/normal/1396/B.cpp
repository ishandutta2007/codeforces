#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int sum = accumulate(a, a + n, 0);
    int maxA = *max_element(a, a + n);
    cout << (maxA * 2 <= sum && sum % 2 == 0 ? "HL\n" : "T\n");
  }
}