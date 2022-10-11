#include <bits/stdc++.h>

using namespace std;

int a[300000];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int k = 0;
  for (int i = 0; i < n; i++) if (a[i] > k) k++;
  cout << k << endl;
}