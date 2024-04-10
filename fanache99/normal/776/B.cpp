//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

bool sieve[1 + MAXN + 1];

void Sieve(int n) {
    for (int i = 2; i * i <= n; i++)
        if (!sieve[i])
            for (int j = 2 * i; j <= n; j += i)
                sieve[j] = true;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    if (n == 2) {
        cout << "1\n1 1\n";
        return 0;
    }
    Sieve(n + 1);
    cout << "2\n";
    for (int i = 2; i <= n + 1; i++)
        if (sieve[i])
            cout << "2 ";
        else
            cout << "1 ";
    return 0;
}