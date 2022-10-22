#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int up = count(s.begin(), s.end(), 'U');
        int dw = count(s.begin(), s.end(), 'D');
        int lf = count(s.begin(), s.end(), 'L');
        int ri = count(s.begin(), s.end(), 'R');
        if ((x < 0 && lf < abs(x)) || (x > 0 && ri < abs(x)))
        {
            cout << "NO\n";
        }
        else if ((y < 0 && dw < abs(y)) || (y > 0 && up < abs(y)))
        {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
    return 0;
}