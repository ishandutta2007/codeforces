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

int n,a[1001005];
long long ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < n; ++i) {
        ans += (long long)a[i] * (long long)(i+2);
    }
    ans -= (long long)a[n-1];
    cout << ans;

    return 0;
}