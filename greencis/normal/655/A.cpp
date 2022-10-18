#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

string a[9], b[9];

int main()
{
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    for (int i = 0; i < 400; ++i) {
        if (a[0] == b[0] && a[1] == b[1]) { cout << "YES"; return 0; }
        if (a[0][0] == 'X') swap(a[0][0], a[0][1]);
        else if (a[0][1] == 'X') swap(a[0][1], a[1][1]);
        else if (a[1][1] == 'X') swap(a[1][1], a[1][0]);
        else if (a[1][0] == 'X') swap(a[1][0], a[0][0]);
    }
    cout << "NO";

    return 0;
}