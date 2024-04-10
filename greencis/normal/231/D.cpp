#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int x,y,z,xa,ya,za,a1,a2,a3,a4,a5,a6;

int main()
{
    cin>>x>>y>>z>>xa>>ya>>za>>a1>>a2>>a3>>a4>>a5>>a6;
    int ans = 0;
    if (y < 0) ans += a1;
    if (y > ya) ans += a2;
    if (x < 0) ans += a5;
    if (x > xa) ans += a6;
    if (z < 0) ans += a3;
    if (z > za) ans += a4;
    cout << ans;

    return 0;
}