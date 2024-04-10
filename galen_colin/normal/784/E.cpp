#include <bits/stdc++.h>

using namespace std;

bool a, b, c, d; 

int main() {
  cin >> a >> b >> c >> d;
  cout << (((bool)((a ^ b) && (c || d))) ^ ((bool)((b && c) || (a ^ d))));
}