#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e5+1;
unordered_map<int, int>f;
int n, p, k;
long long sqr(long long x, int p){
    return x * x % p;
}
int main() {
    scanf("%d %d %d", &n, &p, &k);
    long long ans = 0;
    for (int i = 0; i < n ; i ++){
        int x;
        scanf("%d", &x);
        int v =(sqr(sqr(x, p), p) - (long long)k * x % p  + p ) % p;
        ans += f[v];
        f[v] ++;
    }
    printf("%lld\n", ans);
    return 0;
}