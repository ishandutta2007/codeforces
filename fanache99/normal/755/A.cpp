//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXVAL = 1000001;

bool sieve[1 + MAXVAL];

void Sieve() {
    for (int i = 2; i <= MAXVAL; i++)
        if (!sieve[i])
            if (1LL * i * i <= MAXVAL)
                for (int j = i * i; j <= MAXVAL; j += i)
                    sieve[j] = true;
}

int main() {
    Sieve();
    int n;
    cin >> n;
    for (int i = 1; i <= 1000; i++)
        if (sieve[i * n + 1]) {
            cout << i << "\n";
            return 0;
        }
    return 0;
}