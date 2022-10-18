#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int h,m;
char c;

int main()
{
    cin >> h >> c >> m;
    if (h >= 12) h -= 12;
    cout.precision(17);
    cout << fixed << ld(360) * ld(h*60+m) / ld(12*60) << " ";
    cout.precision(17);
    cout << fixed << ld(6*m) << " ";

    return 0;
}