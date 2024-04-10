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
typedef long long ll;
typedef long double ld;

int n;
char s1[100105],s2[100105];
int ans;

int main()
{
    scanf("%d%s%s",&n,s1,s2);
    int add1 = 0, add2 = 0;
    int i1 = 0, i2 = 0;
    while (i1 < n || i2 < n) { /// 1
        if (s1[i1] == s2[i2]) ++i1, ++i2;
        else {
            if (add1 == 0) add1 = 1, ++i1;
            else if (add2 == 0) add2 = 1, ++i2;
            else { i1 = i2 = 0; break; }
        }
    }
    if (i1 == n && i2 == n)
        ++ans;

    add1 = 0, add2 = 0;
    i1 = 0, i2 = 0;
    while (i1 < n || i2 < n) { /// 2
        if (s1[i1] == s2[i2]) ++i1, ++i2;
        else {
            if (add2 == 0) add2 = 1, ++i2;
            else if (add1 == 0) add1 = 1, ++i1;
            else { i1 = i2 = 0; break; }
        }
    }
    if (i1 == n && i2 == n)
        ++ans;

    cout << ans;

    return 0;
}