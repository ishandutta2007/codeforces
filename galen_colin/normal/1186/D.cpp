#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, q, Q, t, T, m, k;
double a[100003];
bool isi[100003];
const double delta = .0000001;
double sum = 0;

bool close(double a, double b) {
  return a < b + delta && a > b - delta;
}

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  ms(isi, 0);
  f0r(i, n) {
    if (close(a[i], floor(a[i])) && close(a[i], ceil(a[i]))) { 
      isi[i] = 1;
    } else {
      sum -= abs(a[i] - floor(a[i]));
      a[i] = floor(a[i]);
    }
  }
  f0r(i, n) {
    if (close(sum, 0)) break;
    if (!isi[i]) {
      a[i]++;
      sum++;
    }
  }
  f0r(i, n) {
    cout << setprecision(0) << fixed << a[i] << endl;
  }
}