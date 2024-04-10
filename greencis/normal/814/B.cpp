#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a[1005], b[1005], cnt[1005];

int count() {
    int x = 0;
    for (int i = 0; i < n; ++i)
        x += a[i] != b[i];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], ++cnt[a[i]];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int lack = 0, extra = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0)
            lack = i;
        if (cnt[i] == 2)
            extra = i;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == extra) {
            a[i] = lack;
            if (count() == 1) {
                for (int j = 0; j < n; ++j)
                    cout << a[j] << " ";
                return 0;
            }
            a[i] = extra;
        }
    }

    return 0;
}