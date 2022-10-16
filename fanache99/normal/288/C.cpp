//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;
const int MAXLOG = 20;

int p[1 + MAXN];

int main() {
    int n, cn;
    cin >> n;
    cn = n;
    cout << 1LL * n * (n + 1) << "\n";
    int m = 1 << MAXLOG;
    while (n > 0) {
        while (m > n)
            m /= 2;
        for (int i = 0; i <= n - m; i++) {
            p[m + i] = m - i - 1;
            p[m - i - 1] = m + i;
        }
        n = m - (n - m + 1) - 1;
    }
    for (int i = 0; i <= cn; i++)
        cout << p[i] << " ";
    return 0;
}