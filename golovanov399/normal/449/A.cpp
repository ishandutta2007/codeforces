#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    int n, m, k;
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    if (n + m - 2 < k){
        cout << -1 << "\n";
        return 0;
    } else {
        if (k < n){
            cout << max(1ll * n * (m / (k + 1)), 1ll * m * (n / (k + 1))) << "\n";
        } else
        if (k < m){
            cout << max(1ll * m / (k - n + 2), 1ll * n * (m / (k + 1))) << "\n";
        } else
            cout << max(m / (k - n + 2), n / (k - m + 2)) << "\n";
    }

    return 0;
}