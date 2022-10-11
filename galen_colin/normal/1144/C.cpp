#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll i, j;

ll n, q, Q, T, m, k, r, x, y, z, g;
ll b, c, d;
string s;
int a[200001], cnt[200001];
int seq[2][200001], pt[2];

int main() {
  io;
  cin >> n;
  pt[0] = pt[1] = 0;
  f0r(i, n) cin >> a[i];
  f0r(i, n) cnt[a[i]]++;
  f0r(i, n) {
    if (cnt[a[i]] > 2) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  f0r(i, 200001) {
    if (cnt[i] > 0) {
      seq[0][pt[0]++] = i;
      cnt[i]--;
    }
  }
  f0r(i, 200001) {
    if (cnt[i] > 0) {
      seq[1][pt[1]++] = i;
      cnt[i]--;
    }
  }
  sort(seq[0], seq[0]+pt[0]);
  sort(seq[1], seq[1]+pt[1]);
  reverse(seq[1], seq[1]+pt[1]);
  cout << "YES" << endl;
  cout << pt[0] << endl;
  f0r(i, pt[0]) {
    if (i) cout << " ";
    cout << seq[0][i];
  }
  cout << endl;
  cout << pt[1] << endl;
  f0r(i, pt[1]) {
    if (i) cout << " ";
    cout << seq[1][i];
  }
  cout << endl;
}