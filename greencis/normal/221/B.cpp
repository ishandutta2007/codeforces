#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans;

void test(int x) {
    int dig[10] = {};
    int foo = n;
    while (foo) dig[foo % 10] = 1, foo /= 10;
    while (x) {
        if (dig[x % 10]) { ++ans; return; }
        x /= 10;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            test(i);
            if (i * i < n)
                test(n / i);
        }
    }
    cout << ans;

    return 0;
}