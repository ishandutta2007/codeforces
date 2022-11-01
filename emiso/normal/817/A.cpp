#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int x1, y1, x2,  y2, x, y;

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    int distX = abs(x2 - x1);
    int distY = abs(y2 - y1);

    if((distX % x == 0) && (distY % y == 0)) {
        printf("%s\n", ( ((distX / x) % 2) == ((distY / y) % 2)) ? "YES" : "NO");
    }

    else printf("NO\n");

    return 0;
}