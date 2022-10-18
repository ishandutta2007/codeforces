#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long double ld;

ld r,xa,ya,xb,yb;

int main()
{
    cin >> r >> xa >> ya >> xb >> yb;
    cout << ceil(sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) / r / ld(2));
    return 0;
}