#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    if ((n < m && n > 0) || m == 0){
        if (n > 0 && sqrtl(n * n + m * m) + m < sqrtl((n - 1) * (n - 1) + m * m) * 2)
        cout << "1 0\n" << n << " " << m << "\n0 0\n" << n - 1 << " " << m << "\n"; else
        cout << "0 0\n" << n << " " << m << "\n" << n << " 0\n0 " << m << "\n";
    } else {
        if (m > 0 && sqrtl(n * n + m * m) + n < sqrtl((m - 1) * (m - 1) + n * n) * 2)
        cout << "0 1\n" << n << " " << m << "\n0 0\n" << n << " " << m - 1 << "\n"; else
        cout << "0 0\n" << n << " " << m << "\n0 " << m << "\n" << n << " 0\n";
    }

    return 0;
}