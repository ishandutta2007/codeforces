//#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << n / 2 << "\n3 ";
        for (int i = 2; i <= n - 3; i += 2)
            cout << "2 ";
    }
    else {
        cout << n / 2 << "\n";
        for (int i = 2; i <= n; i += 2)
            cout << "2 ";
    }
    return 0;
}