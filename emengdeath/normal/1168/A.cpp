#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
const int N = 1e6;
int a[N], b[N];
int n, m;
bool check(int x) {
    for (int i = 1; i <= n ; i++)
    {
        if (b[i - 1] >= a[i]) {
            if (b[i - 1] - a[i] > x) return 0;
            b[i] = b[i - 1];
        } else {
            if (b[i - 1] + m - a[i] <= x) {
                b[i] = b[i - 1];
            } else
                b[i] = a[i];
        }
    }
    return 1;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);
    int l = 0, r = m, s = m, mid;
    while (l <= r) {
        if (check(mid = (l + r) / 2)) s = min(s, mid), r = mid -1;
        else
            l = mid + 1;
    }
    printf("%d\n", s);
    return 0;
}