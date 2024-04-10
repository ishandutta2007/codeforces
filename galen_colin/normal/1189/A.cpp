#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
int i, j;
typedef long long ll;
typedef pair<int, int> pii;

ll n, q, Q, t, T, m, k;
string s;
int cn[2];

int main() {
  io;
  cin >> n >> s;
  cn[0] = cn[1] = 0;
  f0r(i, n) {
    cn[s[i] - '0']++;
  }
  if (cn[0] != cn[1]) {
    cout << 1 << endl << s << endl;
  } else {
    cout << 2 << endl;
    cout << s.substr(0, s.size() - 1) << " " << s.substr(s.size() - 1, 1) << endl;
  }
}