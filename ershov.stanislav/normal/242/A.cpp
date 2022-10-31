#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int x, y, a, b, minV, n = 0;
    cin >> x >> y >> a >> b;
    minV = max(a, b+1);
    if (minV>x) cout << "0" << endl;
    else {
        for (int i=minV; i<=x; i++)
            for (int j=b; j<i && j<=y; j++) n++;
        cout << n << endl;
        for (int i=minV; i<=x; i++)
            for (int j=b; j<i && j<=y; j++) cout << i << ' ' << j << endl;
    }
}