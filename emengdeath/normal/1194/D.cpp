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
const int N = 1e6;
int T;
int k, n;
int main()
{
    scanf("%d", & T);
    while (T -- ){
        scanf("%d %d", &n, &k);
        if (n < k ) {
            if (n % 3)
                printf("Alice\n");
            else
                printf("Bob\n");
            continue;
        }
        if (n == k) {
            printf("Alice\n");
            continue;
        }
        if (k % 3) {
            if (n % 3 == 0) printf("Bob\n");
            else
                printf("Alice\n");
            continue;
        }
        n -= k;
        bool sig = 0;
        n = n % ((k / 3 - 1) * 3 + 4);
        if (n % 3 == 1 && n / 3 < k / 3 - 1) {
            printf("Bob\n");
            continue;
        }
        if (n == (k /3 - 1) * 3 + 4 - 3) {
            printf("Bob\n");
            continue;
        }
        printf("Alice\n");
    }
    return 0;
}