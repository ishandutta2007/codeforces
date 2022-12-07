#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    int n, m, x1, y1, x2, y2, x, y;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x = abs(x1 - x2);
    y = abs(y1 - y2);
    if (x < y)
    {
        x ^= y;
        y = x ^ y;
        x ^= y;
    }
    if ((x > 4) || ((x == 4) && (y >= 3)))
    {
        cout << "Second" << endl;
        return 0;
    }
    cout << "First" << endl;
    return 0;
}