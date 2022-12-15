#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 2e5+5;

int a[ms];
int b[ms];
int c[ms];

main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    while(x % 2 == 0) {
      x /= 2;
      b[i]++;
    }
    c[b[i]]++;
  }
  int hasMost = 0;
  for(int i = 1; i < 62; i++) {
    if(c[i] > c[hasMost]) {
      hasMost = i;
    }
  }
  cout << n - c[hasMost] << endl;
  for(int i = 0; i < n; i++) {
    if(b[i] != hasMost) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
}