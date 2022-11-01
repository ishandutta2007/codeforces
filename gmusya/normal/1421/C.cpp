#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  cout << 3 << '\n';
  cout << "R " << n - 1 << '\n';
  cout << "L " << n << '\n';
  cout << "L " << 2 << '\n';
  return 0;
}