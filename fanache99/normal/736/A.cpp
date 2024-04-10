//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    long long n;
    cin >> n;
    long long a = 1, b = 2;
    int x = 1;
    while (a + b <= n) {
        long long c = a + b;
        a = b;
        b = c;
        x++;
    }
    cout << x << "\n";
    return  0;
}