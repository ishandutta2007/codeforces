#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], mini = 100, f[55];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
        mini = min(mini, a[i]);
    }

    if(f[mini] > n / 2) puts("Bob");
    else puts("Alice");
    return 0;
}