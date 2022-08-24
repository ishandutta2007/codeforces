#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int r, h;
    cin >> r >> h;
    int ans = 2 * (h / r);
    h %= r;
    if (h * 2 >= r * sqrtl(3)) ans += 3; else
    if (h * 2 >= r) ans += 2; else
    ans++;
    cout << ans << "\n";

    return 0;
}