#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int k,d;

int main()
{
    cin >> k >> d;
    if (d == 0 && k > 1) { cout << "No solution"; return 0; }
    cout << d;
    while (--k) cout << 0;
    return 0;
}