//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    long long n, k, i;
    cin >> n >> k;
    for (i = 1; i * i <= n; i++)
        if (n % i == 0) {
            k--;
            if (!k) {
                cout << i;
                return 0;
            }
        }
    i--;
    if (i * i == n)
        i--;
    for (i; i >= 1; i--)
        if (n % i == 0) {
            k--;
            if (!k) {
                cout << n / i;
                return 0;
            }
        }
    cout << "-1";
    return 0;
}