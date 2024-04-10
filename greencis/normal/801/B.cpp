#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string a, b;

int main()
{
    cin >> a >> b;
    for (int i = 0; b[i]; ++i)
        if (a[i] < b[i])
            cout << -1, exit(0);
    cout << b;

    return 0;
}