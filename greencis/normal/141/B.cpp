#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int a,x,y;

int main()
{
    cin >> a >> x >> y;
    if (x*2 > -a && x*2 < a && y > 0 && y < a) cout << 1;
    else {
        y -= a;
        int row = y / a;
        if (row % 2) {
            if (x > -a && x < 0 && y > row*a && y < row*a+a) cout << 1 + row / 2 * 3 + 2;
            else if (x > 0 && x < a && y > row*a && y < row*a+a) cout << 1 + row / 2 * 3 + 3;
            else cout << -1;
        } else {
            if (x*2 > -a && x*2 < a && y > row*a && y < row*a+a) cout << 1 + row / 2 * 3 + 1;
            else cout << -1;
        }
    }

    return 0;
}