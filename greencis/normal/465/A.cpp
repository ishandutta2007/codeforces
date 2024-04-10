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

int n,ans;
string s1,s2;

int main()
{
    cin >> n >> s1;
    s2 = s1;
    int d = 1;
    for (int i = 0; i < n; ++i) {
         d += s2[i] - 48;
         s2[i] = '0' + d%2;
         d/=2;
    }
    for (int i = 0; i < n; ++i) 
        ans += s2[i] != s1[i];
    cout << ans;

    return 0;
}