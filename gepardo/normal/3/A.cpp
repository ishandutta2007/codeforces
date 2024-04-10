#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



int main()
{
    char sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    string a[9]; int u = 0;
    while (sx != dx || sy != dy)
    {
        a[u] = "";
        if (sx < dx)
        {
            a[u] += "R";
            sx++;
        }
        else
        if (sx > dx)
        {
            a[u] += "L";
            sx--;
        }
        if (sy < dy)
        {
            a[u] += "U";
            sy++;
        }
        else
        if (sy > dy)
        {
            a[u] += "D";
            sy--;
        }
        u++;

    }
    cout << u << endl;
    for (int i = 0; i < u; i++) cout << a[i] << endl;
}