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
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
int T;
int n ,x;
int calc(int x) {
    int l = 1, r = n , mid, s = n;
    while (l <= r){
        mid = (l + r) / 2;
        if (mid <= x - mid + 1) s = min(s, x - mid), l = mid + 1;
        else
            r = mid - 1;
    }
    return s;
}
int main()
{
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &x);
        int l = 1, r = n, mid, s = n;
        while (l <= r)
            if (calc(mid = (l + r) /2 ) >= x) s = min(mid, s), r = mid - 1;
            else
                l = mid + 1;
        printf("%d\n", s);
    }
    return 0;
}