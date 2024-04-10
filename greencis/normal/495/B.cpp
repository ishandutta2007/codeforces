#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int a,b,z,ans;

int main()
{
    cin >> a >> b;
    if (a - b < 0) cout << 0;
    else if (a == b) cout << "infinity";
    else {
        z = a-b;
        for (int i = 1; i * i <= z; ++i) {
            if (a % i == b) ++ans;
            if (i * i != z) {
                if (a % (z / i) == b) ++ans;
            }
        }
        cout << ans;
    }

    return 0;
}