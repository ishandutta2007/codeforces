#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        int n;
        long long s;
        scanf("%d%lld", &n, &s);

        printf("%lld\n", s / (n * 1ll * n));
    }

    return 0;
}