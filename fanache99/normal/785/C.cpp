//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    unsigned long long n, m;
    cin >> n >> m;
    if (n <= m) {
        cout << n << "\n";
        return 0;
    }
    unsigned long long left = 1, right = 2e9, answer = 2e9;
    while (left <= right) {
        unsigned long long middle = (left + right) / 2;
        if (middle * (middle + 1) / 2 >= n) {
            answer = middle;
            right = middle - 1;
            continue;
        }
        if (n - middle * (middle - 1) / 2 <= m + middle) {
            answer = middle;
            right = middle - 1;
            continue;
        }
        left = middle + 1;
    }
    cout << answer + m << "\n";
    return 0;
}