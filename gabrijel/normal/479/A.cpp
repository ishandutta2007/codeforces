#include <bits/stdc++.h>
using namespace std;

int a, b, c, rj = 0;

int main()
{
    cin >> a >> b >> c;
    rj = max(rj, a * b + c);
    rj = max(rj, a + b * c);
    rj = max(rj, a + b + c);
    rj = max(rj, a * b * c);
    rj = max(rj, a * (b + c));
    rj = max(rj, (a + b) * c);
    cout << rj;
    return 0;
}