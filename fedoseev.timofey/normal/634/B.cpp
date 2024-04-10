#include <iostream>	
#include <string>	
#include <vector>	
#include <queue>	
#include <deque>	
#include <stack>	
#include <set>	
#include <map>	
#include <unordered_map>	
#include <unordered_set>	
#include <cstring>	
#include <cmath>	
#include <cstdlib>	
#include <algorithm>	
#include <random>	
#include <iomanip>	
#include <functional>	
#include <cassert>	
 	
typedef long long ll;

using namespace std;	
 
int main() {	
  ios_base::sync_with_stdio(false); cin.tie(0);	
#ifdef LOCAL	
  freopen("input.txt", "r", stdin);	
#endif	
  ll s, x;
  cin >> s >> x;
  if (x > s) {
    cout << "0\n";
    return 0;
  }
  ll need = s - x;
  if (need % 2) {
    cout << "0\n";
    return 0;
  }
  need /= 2;
  if (need & x) {
    cout << "0\n";
    return 0;
  }
  ll ans = 1LL << __builtin_popcountll(x);
  if (s == x) ans -= 2;
  cout << ans << '\n';
}