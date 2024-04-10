#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005],cnt[100005],u[100005];
int cur = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], ++cnt[a[i]], u[a[i]] |= a[i] > n;
    for (int i = 0; i < n; ++i)
        if (!u[a[i]]) u[a[i]] = 1;
        else {
            while (1) {
                if (cnt[cur] == 0 && !u[cur]) break;
                ++cur;
            }
            u[cur] = 1;
            a[i] = cur;
        }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";

    return 0;
}