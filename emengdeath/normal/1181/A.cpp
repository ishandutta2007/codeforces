#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;
    if (x / z + y / z != (x + y) / z)
        cout << (x + y) / z << ' ' << min(z - x % z, z - y % z);
    else    cout << (x + y) / z << ' ' << 0;

    return 0;
}