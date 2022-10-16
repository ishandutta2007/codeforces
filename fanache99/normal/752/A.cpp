//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int lane = k / (2 * m);
    if (k % (2 * m) != 0)
        lane++;
    cout << lane << " ";
    k = k - (lane - 1) * 2 * m;
    if (k % 2 == 1)
        cout << k / 2 + 1 << " L\n";
    else
        cout << k / 2 << " R\n";
    return 0;
}