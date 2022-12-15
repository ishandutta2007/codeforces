#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long caso1 = ((a+b)*x*y-1)/(x*y-1);
    long long caso2 = (a*x-1)/(x-1);
    long long caso3 = (b*y-1)/(y-1);
    //cout << caso1 << " " << caso2 << " " << caso3 << endl;
    cout << max(caso1, max(caso2, caso3)) << endl;
    return 0;
}