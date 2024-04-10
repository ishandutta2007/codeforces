#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

int main()
{
    long long n, m;
    long long k;
    cin >> n >> m >> k;
    long long l = 0, r = 1ll * n * m;
    while (r - l > 1){
        long long mid = (l + r) / 2;
        long long s = 0;
        for (int i = 1; i <= n; i++) s += min(mid / i, m);
        if (s < k) l = mid; else r = mid;
    }
    cout << r << "\n";

    return 0;
}