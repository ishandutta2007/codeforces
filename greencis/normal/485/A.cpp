#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int u[200005],a,m;

int main()
{
    cin >> a >> m;
    while (!u[a]) {
        u[a] = 1;
        (a += a % m) %= m;
    }
    if (u[0]) cout << "Yes";
    else cout << "No";

    return 0;
}