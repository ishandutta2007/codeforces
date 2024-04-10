#include <iostream>

using namespace std;

int main()
{
    int m[5][5];
    for (int i=0;i<5;++i)
        for (int j = 0; j < 5; ++j)
            cin >> m[i][j];
    if (m[0][0] == 1) cout << 4;
    if (m[0][1] == 1) cout << 3;
    if (m[0][2] == 1) cout << 2;
    if (m[0][3] == 1) cout << 3;
    if (m[0][4] == 1) cout << 4;

    if (m[1][0] == 1) cout << 3;
    if (m[1][1] == 1) cout << 2;
    if (m[1][2] == 1) cout << 1;
    if (m[1][3] == 1) cout << 2;
    if (m[1][4] == 1) cout << 3;

    if (m[2][0] == 1) cout << 2;
    if (m[2][1] == 1) cout << 1;
    if (m[2][2] == 1) cout << 0;
    if (m[2][3] == 1) cout << 1;
    if (m[2][4] == 1) cout << 2;

    if (m[3][0] == 1) cout << 3;
    if (m[3][1] == 1) cout << 2;
    if (m[3][2] == 1) cout << 1;
    if (m[3][3] == 1) cout << 2;
    if (m[3][4] == 1) cout << 3;

    if (m[4][0] == 1) cout << 4;
    if (m[4][1] == 1) cout << 3;
    if (m[4][2] == 1) cout << 2;
    if (m[4][3] == 1) cout << 3;
    if (m[4][4] == 1) cout << 4;
    return 0;
}