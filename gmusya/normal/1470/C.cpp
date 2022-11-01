#include <iostream>

using namespace std;

int get(int x) {
  cout << "? " << x + 1 << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  int n, k;
  cin >> n >> k;
  int pos = 0, toadd = 1;
  int cur = get(0);
  while (cur >= k) {
    pos = (pos + toadd++) % n;
    cur = get(pos);
  }
  while (cur != k) {
    pos = (pos + 1) % n;
    cur = get(pos);
  }
  cout << "! " << pos + 1;
  return 0;
}