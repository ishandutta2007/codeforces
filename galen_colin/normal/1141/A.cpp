#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void end(int i) {
  cout << i << endl;
  exit(0);
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b % a != 0) end(-1);
    int mov = 0;
    b /= a;
    while (b % 2 == 0) {
      b /= 2;
      mov++;
    }
    while (b % 3 == 0) {
      b /= 3;
      mov++;
    }
    if (b != 1) end(-1);
    end(mov);
}