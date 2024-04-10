#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int n,a[500005];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    int cur = a[0];
    for (int i = 1; i < n; ++i) cur = gcd(cur, a[i]);
    for (int i = 0; i < n; ++i) a[i] /= cur;
    for (int i = 0; i < n; ++i) {
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
        if (a[i] != 1) { cout << "No"; return 0; }
    }
    cout << "Yes";

    return 0;
}