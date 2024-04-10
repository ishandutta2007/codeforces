#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,X0,Y0,x,y;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
map< pii ,int> mp;

int main()
{
    cin >> n >> X0 >> Y0;
    while (n--) {
        cin >> x >> y;
        x -= X0;
        y -= Y0;
        pii coef;
        if (x == 0) coef = make_pair((int)2e9,(int)2e9);
        else {
            int g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            if (x < 0) x = -x, y = -y;
            coef = make_pair(x, y);
        }
        ++mp[coef];
    }
    cout << mp.size();
    return 0;
}