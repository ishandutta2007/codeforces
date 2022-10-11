#include <bits/stdc++.h>

using namespace std;

int a;

int main() {
  cin >> a;
  cout << (((a == 5) ? 1 : 0) + a) % 3 + 1 << endl;
}