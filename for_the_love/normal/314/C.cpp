#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1111111;
const long long MOD = 1e9 + 7;
long long b[N + 5], a[N + 5];
int n;


inline int lowbit(int x){return x & -x;}

void Add(int x, long long d){
    for (; x <= N; x += lowbit(x))
        b[x] = (b[x] + d + MOD * 10000) % MOD;
}
long long Query(int x){
    long long ret = 0;
    for (; x; x -= lowbit(x))
        ret = (ret + b[x] + MOD * 10000) % MOD;
    return ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        long long x;
        scanf("%I64d", &x);
        long long t = (Query(x) * x + x) % MOD;
        Add(x, -a[x]);
        a[x] = t;
        Add(x, a[x]);
    }
    cout << (Query(N) + MOD * 10000) % MOD << endl;

}