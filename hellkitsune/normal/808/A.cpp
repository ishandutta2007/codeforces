#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    cin >> n;
    int mul = 1;
    while (true) {
        for (int i = 1; i <= 9; ++i) {
            int num = i * mul;
            if (num > n) {
                cout << num - n << endl;
                return 0;
            }
        }
        mul *= 10;
    }
    return 0;
}