#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long double ld;
typedef long long ll;

int n;

int main()
{
    cin >> n;
    while (n >= 7) n -= 7, cout << "ROYGBIV";
    if (n == 0) cout << "";
    else if (n == 1) cout << "G";
    else if (n == 2) cout << "GB";
    else if (n == 3) cout << "GBI";
    else if (n == 4) cout << "GBIV";
    else if (n == 5) cout << "YGBIV";
    else if (n == 6) cout << "OYGBIV";
}