#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int f(int num) {
    int cnt = 0;
    while (num % 2 == 0) ++cnt, num /= 2;
    while (num % 3 == 0) ++cnt, num /= 3;
    while (num % 5 == 0) ++cnt, num /= 5;
    if (num != 1) cnt = 1e9;
    return cnt;
}

int main()
{
    cin >> n >> m;
    int g = gcd(n, m);
    int a = f(n / g), b = f(m / g);
    if (a + b < 1e9) cout << a + b;
    else cout << -1;

    return 0;
}