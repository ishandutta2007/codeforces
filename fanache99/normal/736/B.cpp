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

bool Prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    if (Prime(n))
        cout << "1\n";
    else
        if (n % 2)
            if (Prime(n - 2))
                cout << "2\n";
            else
                cout << "3\n";
        else
            cout << "2\n";
    return  0;
}