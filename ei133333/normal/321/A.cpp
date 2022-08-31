#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

const string s = "UDLR";
const int vy[] = {1, -1, 0, 0};
const int vx[] = {0, 0, -1, 1};

int main() {
  int64 A, B;
  cin >> A >> B;
  if(A == 0 && B == 0) {
    puts("Yes");
    exit(0);
  }
  int X = 0, Y = 0;
  string S;
  cin >> S;
  for(auto &c : S) {
    X += vx[s.find(c)];
    Y += vy[s.find(c)];
    if(X == A && Y == B) {
      puts("Yes");
      exit(0);
    }
  }
  if(X == 0 && Y == 0) {
    puts("No");
    exit(0);
  }
  int64 p = (X == 0 ? INF : A / X);
  int64 q = (Y == 0 ? INF : B / Y);
  int64 r = max(min(p, q) - 200, 0LL);
  X *= r, Y *= r;
  for(int i = 0; i < 500; i++) {
    for(auto &c : S) {
      X += vx[s.find(c)];
      Y += vy[s.find(c)];
      if(X == A && Y == B) {
        puts("Yes");
        exit(0);
      }
    }
  }
  puts("No");
}