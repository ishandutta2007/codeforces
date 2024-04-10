#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    int was2 = 0;
    for (int i = 2; i <= n + 1; ++i) {
        if (!a[i]) {
            a[i] = 1;
            for (int j = i + i; j <= n + 1; j += i)
                a[j] = 2, was2 = 1;
        }
    }
    cout << 1 + was2 << endl;
    for (int i = 2; i <= n + 1; ++i)
        cout << a[i] << " ";

    return 0;
}