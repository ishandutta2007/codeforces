#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    /*
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x - 1] = i;
    }
    for (int i = 0; i < n; i++){

    }
    cout << "NO\n";

    return 0; */

    int n, m;
    cin >> n >> m;
    cout << setprecision(10) << fixed;
    if (n == 1 && m == 1) cout << "1.0000000000\n"; else
    cout << 1.0 / n + 1.0 * (n - 1) * (m - 1) / (m * n - 1) / n << "\n";

    return 0;

}