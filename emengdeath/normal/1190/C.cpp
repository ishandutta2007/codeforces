#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1;
int n, k;
char a[N], b[N];
int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", a);
    int l = 0, r = n - 1, l1, r1;
    while (l <= r  && a[l] == '0') l ++;
    while (l <= r && a[r] == '0') r --;
    if (l > r || r - l + 1 <=k) {
        printf("tokitsukaze");
        return 0;
    }
    l1 = l, r1 = r;
    l = 0, r = n - 1;
    while (l <= r  && a[l] == '1') l ++;
    while (l <= r && a[r] == '1') r --;
    if (l > r || r - l + 1 <=k) {
        printf("tokitsukaze");
        return 0;
    }
    if (r - l + 1 >= k + 2 || r1 - l1 + 1 >= k + 2 || r - max(l, k) + 1 > k || r1 - max(r1, k) + 1 > k || min(r, n - k - 1) - l + 1 > k || min(r1, n - k - 1) - l1 + 1 > k){
        printf("once again");
        return 0;
    }
    printf("quailty\n");
    return 0;
}