#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n,a[1001005],res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
     cin >> a[i];
    bool opened = false;
    for (int i = 0; i < n; ++i) {
     if (a[i]) {
      res += 1;
      opened = 1;
     } else {
      res += opened;
      opened = 0;
     }
    }
    if (!opened) res = max(0,res-1);
    cout << res;
    
    return 0;
}