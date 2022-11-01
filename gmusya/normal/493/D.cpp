#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << "white\n1 2";
  else
    cout << "black";
  return 0;
}