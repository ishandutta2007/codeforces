#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int N = 2e5 + 1;
pair<int, int>a[N];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)scanf("%d", &a[i].first), a[i].second = i;
    if (n <= 2) {
        printf("1\n");
        return 0;
    }
    sort(a + 1, a + n + 1);
    int x = a[2].first - a[1].first;
    int sig = 0, y = 0;
    for (int i = 3; i <= n && sig < 2; i ++)
        if (a[i].first - a[1].first != (long long)(i - 1 - sig) * x) {
            sig++;
            y = a[i].second;
        }
    if (sig == 0) {
        printf("%d", a[1].second);
        return 0;
    }
    if (sig == 1) {
        printf("%d", y);
        return 0;
    }
    x = a[3].first - a[1].first;
    sig = 1;
    for (int i = 4; i <= n && sig; i ++)
        if (a[i].first - a[1].first != (long long)(i - 2) * x) {
            sig = 0;
        }
    if (sig) {
        printf("%d", a[2].second);
        return 0;
    }
    x = a[3].first - a[2].first;
    sig = 1;
    for (int i = 4; i <= n && sig; i ++)
        if (a[i].first - a[2].first != (long long)(i - 2) * x) {
            sig = 0;
        }
    if (sig) {
        printf("%d", a[1].second);
        return 0;
    }
    printf("-1");
    return 0;
}