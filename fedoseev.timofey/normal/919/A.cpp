#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double ans = 1e9;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        ans = min(ans, m * a / b);
    }
    cout << fixed << setprecision(16) << ans << endl;
}