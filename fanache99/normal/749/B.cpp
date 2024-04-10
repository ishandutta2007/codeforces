//#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    cout << "3\n";
    cout << a1 + a2 - a3 << " " << b1 + b2 - b3 << "\n";
    cout << a1 - a2 + a3 << " " << b1 - b2 + b3 << "\n";
    cout << - a1 + a2 + a3 << " " << - b1 + b2 + b3 << "\n";
    return 0;
}