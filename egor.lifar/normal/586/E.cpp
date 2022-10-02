#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>


using namespace std;


long long x, y;


long long gcd(long long a, long long b) {
    if (a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}
        

int main() {
    cin >> x >> y;
    if (gcd(x, y) != 1LL) {
        printf("Impossible\n");
        return 0;
    }
    char a = 'A';
    char b = 'B';
    while (!(x == 1 && y == 1)) {
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        printf("%I64d%c", (x - 1) / y, a);
        x = x - (x - 1) / y * y;
    }
    printf("\n");
    return 0;   
}