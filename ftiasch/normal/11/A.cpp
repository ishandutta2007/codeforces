// Codeforces Beta Round #11
// Problem A -- Increasing Sequence
#include <iostream>

#define maxN 2000

using namespace std;

long long n, d, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> d >> a;
    long long s = 0;
    for(int i = 1; i != n; ++ i)
    {
        cin >> b;
        long long t = a < b? 0: (a - b) / d + 1;
        s += t, a = b + t * d;
    }
    cout << s << "\n";
    return 0;
}