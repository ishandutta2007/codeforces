#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


int k, b, n;
int a[111111];
map<int, int> f;


int main() {
 scanf("%d %d %d", &k, &b, &n);
 for(int i = 0; i < n; i++) {
 	scanf("%d", &a[i]);
 }
 long long zeros = 0;
 if (b == 0 || b == k - 1) {
  int last = 0;
  for (int i = 0; i < n; i++) { 
  	if (!a[i]) {
  		last++;
  	} else {
  		last = 0; 
  	}
  	zeros += last; 
  }
  if (b == 0) { 
  	cout << zeros << endl; 
  	return 0; 
  }
 }
 if (b == k - 1) {
 	b = 0;
 }
 f[0] = 1;
 int ps = 0;
 long long ans = 0;
 for (int i = 0; i < n; i++) {
  ps = (ps + a[i]) % (k - 1);
  ans += f[(ps - b + k - 1) % (k - 1)];
  f[ps]++;
 }
 if (b == 0) {
 	ans -= zeros;
 }
 cout << ans << endl;
 return 0;
}