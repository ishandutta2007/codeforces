#include <bits/stdc++.h>
 
using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;
 
ll n, p, q, Q, k, r;
string s1, s2, s3;
int a[2], b[2], c[2];
 
int main() {
  io; int x;
  cin >> s1 >> s2 >> s3;
  a[0] = s1[0] - '0';
  a[1] = s1[1];
  b[0] = s2[0] - '0';
  b[1] = s2[1];
  c[0] = s3[0] - '0';
  c[1] = s3[1];
  pair<int, int> d[3] = {{a[0], a[1]}, {b[0], b[1]}, {c[0], c[1]}};
  sort(d, d+3);
  a[0] = d[0].first;
  a[1] = d[0].second;
  b[0] = d[1].first;
  b[1] = d[1].second;
  c[0] = d[2].first;
  c[1] = d[2].second;
  if (a[1] == b[1]) {
    if (a[0] == b[0]) { //first two equal
      if (c[0] == b[0] && c[1] == b[1]) {
        cout << 0 << endl;
        exit(0);
      } else {
        cout << 1 << endl;
        exit(0);
      }
    } else if (a[0] == b[0] - 1) {
      if (c[1] == b[1] && c[0] == b[0] + 1) {
        cout << 0 << endl;
        exit(0);
      } else {
        cout << 1 << endl;
        exit(0);
      }
    }
  }
  swap(a[0], c[0]);
  swap(a[1], c[1]);
  if (a[1] == b[1]) {
    if (a[0] == b[0]) { //first two equal
      if (c[0] == b[0] && c[1] == b[1]) {
        cout << 0 << endl;
        exit(0);
      } else {
        cout << 1 << endl;
        exit(0);
      }
    } else if (a[0] == b[0] + 1) {
      if (c[1] == b[1] && c[0] == b[0] - 1) {
        cout << 0 << endl;
        exit(0);
      } else {
        cout << 1 << endl;
        exit(0);
      }
    }
  }
 
  if (a[1] == c[1]) {
    if (a[0] == c[0] + 2) {
      cout << 1 << endl;
      exit(0);
    } else if (a[0] == c[0] + 1) {
      cout << 1 << endl;
      exit(0);
    }
  }
  if (a[1] == b[1]) {
    if (a[0] == b[0] + 2) {
      cout << 1 << endl;
      exit(0);
    }
  }
  if (b[1] == c[1]) {
    if (b[0] == c[0] + 2) {
      cout << 1 << endl;
      exit(0);
    }
  }
  cout << 2 << endl;
}