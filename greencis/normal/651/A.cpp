#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int ans,a,b;

int main()
{
    cin >> a >> b;
    while (a > 0 && b > 0 && (a > 1 || b > 1)) {
        if (a < b) a += 1, b -= 2;
        else b += 1, a -= 2;
        ++ans;
    }
    cout << ans;

    return 0;
}