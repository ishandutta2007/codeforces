#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
typedef pair <Pii, int> PPi;
#define x first
#define y second
#define mp make_pair

LL a, b, c, ans;

int main()
{
    cin >> a >> b >> c;
    if (a == 1 && b == 1 && c == 1) ans = a + b + c;
    else if (a == 1 && b == 1) ans = 2 * c;
    else if (a == 1 && c == 1) ans = a + b + c;
    else if (b == 1 && c == 1) ans = 2 * a;
    else if (a == 1) ans = (a + b) * c;
    else if (b == 1) ans = (min(a, c) + 1) * max(a, c);
    else if (c == 1) ans = a * (b + c);
    else ans = a * b * c;
    
    cout << ans << endl;
    return 0;
}