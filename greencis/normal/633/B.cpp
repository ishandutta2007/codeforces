#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,cur;

int main()
{
    cin >> n;
    for (int i = 1; cur <= n; ++i) {
        int x = i;
        while (x % 5 == 0) ++cur, x /= 5;
        if (cur == n) {
            cout << 5 << "\n" << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << " " << i + 4;
            return 0;
        }
    }
    cout << 0;

    return 0;
}