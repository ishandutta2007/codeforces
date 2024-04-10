#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool pr[333333];

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        return false;
    }
    return true;
}

int main() {
    REP(i, 333333) pr[i] = true;
    pr[0] = pr[1] = false;
    for (int i = 2; i < 3333; ++i) if (pr[i]) {
        for (int j = i * i; j < 333333; j += i) {
            pr[j] = false;
        }
    }
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("1\n%d\n", n);
        return 0;
    }
    if (isPrime(n - 2)) {
        printf("2\n2 %d\n", n - 2);
        return 0;
    }
    if (isPrime(n - 4)) {
        printf("3\n2 2 %d\n", n - 4);
        return 0;
    }
    for (int i = n - 2; i > 1; i -= 2) {
        if (isPrime(i)) {
            int rem = n - i;
            for (int j = 3; j < rem - 1; j += 2) {
                if (pr[j] && pr[rem - j]) {
                    printf("3\n%d %d %d\n", i, j, rem - j);
                    return 0;
                }
            }
        }
    }
    return 0;
}