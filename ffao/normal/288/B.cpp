#include <stdio.h>
#include <iostream>

using namespace std;

int n, k;
const int MOD = 1000000007;

int main() {
    scanf("%d %d", &n, &k);

    long long res = 1;
    for (int i = 0; i < k-1; i++) res = (res * k) % MOD;
    for (int i = 0; i < n-k; i++) res = (res * (n-k)) % MOD;

    cout << res << endl;
}