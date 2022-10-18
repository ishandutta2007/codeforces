#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int a;

int main()
{
    cin >> a;
    for (int i = 1; ; ++i) {
        ++a;
        int good = 0, foo = a;
        while (foo) {
            good |= abs(foo) % 10 == 8, foo /= 10;
        }
        if (good) { cout << i; return 0; }
    }

    return 0;
}