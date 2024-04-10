#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
ll i, j;


ll n, m, p, q, Q, k, r;
string s;
vector<ll> ind[2];
set<ll> indset[2][2];

void end() {
  cout << "once again" << endl;
  exit(0);
}

int main() {
  io;
  cin >> n >> k >> s;
  f0r(i, n) {
    ind[s[i] - '0'].pb(i);
    indset[s[i] - '0'][0].insert(i);
    indset[s[i] - '0'][1].insert(-i);
  }
  //check if win on first move
  int z = ind[0].size(), o = ind[1].size();
  if (z == 0 || o == 0) {
    cout << "tokitsukaze" << endl;
    exit(0);
  }
  if (ind[0][z-1] - ind[0][0] < k || ind[1][o-1] - ind[1][0] < k) {
    cout << "tokitsukaze" << endl;
    exit(0);
  }
  //try all first move
  f0r(i, n - k + 1) {
    //see if second move HAS to win
    int l0, r0, l1, r1;
  
    //try set to 0
    l0 = min(i, ind[0][0]);
    r0 = max(i + k - 1, ind[0][z-1]);
    //left 1 is covered
    if (ind[1][0] >= i && ind[1][0] < i + k) {
      l1 = *indset[1][0].upper_bound(i + k - 1);
    } else {
      l1 = ind[1][0];
    }
    if (ind[1][o-1] >= i && ind[1][o-1] < i + k) {
      r1 = *indset[1][1].upper_bound(-i);
    } else {
      r1 = ind[1][o-1];
    }
    if (r0 - l0 >= k && r1 - l1 >= k) end();

    //try set to 1
    l0 = min(i, ind[1][0]);
    r0 = max(i + k - 1, ind[1][o-1]);
    //left 0 is covered
    if (ind[0][0] >= i && ind[0][0] < i + k) {
      l1 = *indset[0][0].upper_bound(i + k - 1);
    } else {
      l1 = ind[0][0];
    }
    if (ind[0][z-1] >= i && ind[0][z-1] < i + k) {
      r1 = *indset[0][1].upper_bound(-i);
    } else {
      r1 = ind[0][z-1];
    }
    if (r0 - l0 >= k && r1 - l1 >= k) end();
  }
  cout << "quailty" << endl;
}