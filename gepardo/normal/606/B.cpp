#include <iostream>
#include <string>

using namespace std;

int x, y, x0, y0;
bool used[1000][1000] = {};
int bug;

int move(char c)
{
    if (c == 'L') y0--;
    if (c == 'R') y0++;
    if (c == 'U') x0--;
    if (c == 'D') x0++;
    if (x0 < 1) x0 = 1;
    if (x0 > x) x0 = x;
    if (y0 < 1) y0 = 1;
    if (y0 > y) y0 = y;
    int v = !used[x0][y0];
    used[x0][y0] = true;
    bug -= v;
    return v;
}

int main()
{
    cin >> x >> y >> x0 >> y0;
    bug = x * y;
    string s;
    getline(cin, s);
    getline(cin, s);
    used[x0][y0] = true;
    cout << 1 << " ";
    bug--;
    int n = s.length();
    for (int i = 0; i < (n - 1); i++) cout << move(s[i]) << " ";
    cout << bug;
}