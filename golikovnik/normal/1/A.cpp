#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, m, a;
    cin >> n;
    cin >> m;
    cin >> a;
    long long  ans = ceil (m/a) * ceil (n/a);
    cout << ans << endl;
    return 0;
}