#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
 
using namespace std;

int n, q, k;

long long a[1100000];
long long soma[1100000];
long long calc[1100000];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    for (int i = 1; i <= n; i++) {
        soma[i] = soma[i-1] + a[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        if (calc[k] == 0) {
            long long dec = 1;
            for (long long j = n-1; j >= 1; j-=dec) {
                calc[k] += soma[j];
                dec *= k;
            }
        }
        cout << calc[k] << " ";
    }
}