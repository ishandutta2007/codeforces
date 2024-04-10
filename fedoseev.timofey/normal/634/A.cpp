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
  int n;
  cin >> n;
  vector <int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x != 0) a.push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x != 0) b.push_back(x);
  }
  rotate(b.begin(), find(b.begin(), b.end(), a[0]), b.end());
  if (a == b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}