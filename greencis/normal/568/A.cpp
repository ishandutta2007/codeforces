#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 11001001;
int p,q,u[MAXN];
int ans = 1, curpr, curpal = 1;

bool ispalynd(int num) {
    if (num % 10 == 0) return !num;
    int qqq1 = num, qqq2 = 0;
    while (qqq1) qqq2 = qqq2 * 10 + qqq1 % 10, qqq1 /= 10;
    return qqq2 == num;
}

int main()
{
    cin >> p >> q;
    for (int i = 2; i < MAXN; ++i) u[i] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (ispalynd(i)) ++curpal;
        if (u[i]) {
            ++curpr;
            for (int j = i + i; j < MAXN; j += i) u[j] = 0;
        }
        if ((ll)curpr * (ll)q <= (ll)p * (ll)curpal) ans = i;
    }
    cout << ans;

    return 0;
}