//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n;
    cin >> n;
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ((4 + 2 * (x1 % 2) + (y1 % 2)) % 4) + 1 << "\n";
    }
    return 0;
}