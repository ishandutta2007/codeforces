#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n;
string s;
int a[200002];

int main() {
  io;
  cin >> n >> s;
  f0r(i, n) cin >> a[i];
  int m = -2;
  f0r(i, n - 1) {
  	if (s[i] == 'R' && s[i + 1] == 'L') {
  		if (m == -2) m = a[i + 1] - a[i];
  		else m = min(a[i + 1] - a[i], m);
  	}
  }
  cout << m/2 << endl;
}