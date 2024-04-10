#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;
    cout << setprecision(10) << (l - d) / (v1 + v2);
}