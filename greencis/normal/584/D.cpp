#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
vector<int> v, v2;

bool pr(int x) {
    if (x < 2) return 0;
    for (int j = 0; v2[j] <= x; ++j)
        if (x % v[j] == 0) return 0;
    return 1;
}

int main()
{
    for (int i = 2; i <= 32000; ++i) {
        int g = 1;
        for (int j = 0; j < v.size(); ++j)
            if (i % v[j] == 0) { g = 0; break; }
        if (g)
            v.push_back(i), v2.push_back(i * i);
    }

    cin >> n;
    if (pr(n)) { cout << "1\n" << n; return 0; }

    for (int j = 0; ; ++j) {
        if (v[j] + 3 == n) {
            cout << "2\n3 " << v[j]; return 0;
        }
        if (pr(n - v[j] - 3)) {
            cout << "3\n3 " << v[j] << " " << n - v[j] - 3; return 0;
        }
    }

    return 0;
}