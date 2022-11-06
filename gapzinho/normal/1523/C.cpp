#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
#define endl '\n'

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;
int a[ms];
int b[ms];
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> curV(n);
    int curVSz = 0;
    int lst = 0;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x == 1) {
        curV[curVSz++] = 1;
      } else {
        while(x != curV[curVSz-1]+1) {
          curVSz--;
        }
      curV[curVSz-1]++;
      }
      for(int j = 0; j < curVSz; j++) {
        cout << curV[j];
        if(curVSz == j+1) cout << "\n";
        else cout << ".";
      }
    }
  }
    
  return 0;
}