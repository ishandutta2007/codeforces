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

int n,a[500505];
long long sum[500505];
long long ans;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    if (n < 3 || sum[n] % 3ll) {printf("0"); return 0;}
    long long sum3 = sum[n] / 3ll;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (sum[i] == 2 * sum3)
            ans += cnt;
        if (sum[i] == sum3) ++cnt;
    }
    cout << ans;

    return 0;
}