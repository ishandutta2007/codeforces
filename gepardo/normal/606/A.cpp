#include <iostream>
#define do(f, s) if (f > s) mn += (f - s) / 2; else pl += (s - f);

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int mn = 0, pl = 0;
    do(a, d); do(b, e); do(c, f);
    //cout << mn << " " << pl << endl;
    if (mn < pl) cout << "No"; else cout << "Yes";
}