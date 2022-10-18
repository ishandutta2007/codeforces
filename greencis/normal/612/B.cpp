#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x,pos[200105];
ll ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        pos[x] = i;
    }
    for (int i = 2; i <= n; ++i)
        ans += abs(pos[i] - pos[i-1]);
    cout << ans;

    return 0;
}