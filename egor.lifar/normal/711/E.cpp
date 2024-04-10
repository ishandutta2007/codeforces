#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


const int Mod = 1e6 + 3;


inline int fpm(long long b, long long e, int m) {
    b %= m;
    long long t = 1;
    for ( ; e; e >>= 1, (b *= b) %= m){
        if (e & 1) {
            (t *= b) %= m;
        }
    }
    return t;
}

long long n, k;
int num[(Mod << 1) + 5];


inline int calc(int from, const long long &x) {
    num[0] = 1;
    for (int i = 0; i < Mod << 1; i++) {
        num[i + 1] = num[i];
        if (i & 1) {
            num[i + 1] = (long long)num[i + 1] * (from - i) % Mod;
        }
    }
    return (long long)fpm(num[Mod << 1], x / (Mod << 1), Mod) * num[x % (Mod << 1)] % Mod;
}


int main() {
    cin >> n >> k;
    if (n <= 60 && k > 1LL << n) {
        puts("1 1");
        return 0;
    }
    int tmp = (n % (Mod - 1)) * ((k - 1) % (Mod - 1)) % (Mod - 1);
    int num = 1;
    while (k > 1) {
        (tmp -= ((k - 1) >> 1) % (Mod - 1)) %= Mod - 1;
        num = (long long)num * calc(fpm(2, n, Mod), k) % Mod;
        n--;
        k = (k + 1) >> 1;
    }
    (tmp += Mod - 1) %= Mod - 1;
    int dom = fpm(2, tmp, Mod);
    num = (dom - num) % Mod; 
    (num += Mod) %= Mod;
    printf("%d %d\n", num, dom);
    return 0;
}