#include <bits/stdc++.h>

using namespace std;

int a;
string b;

int main() {
  cin >> a >> b;
  reverse(b.begin(), b.end());
  cout << a + stoi(b);
}