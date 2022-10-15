#include <iostream>
#include <vector>

using namespace std;

int len[100][2000];

int main()
{
    int v1, v2, t, d; cin >> v1 >> v2 >> t >> d;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < 2000; j++)
            len[i][j] = -12345678;
    len[0][v1] = v1;

    for (int i = 1; i < t; i++)
        for (int j = 0; j < 1500; j++)
            for (int k = j - d; k <= j + d; k++)
                if (k >= 0)
                    len[i][j] = max(len[i][j], len[i - 1][k] + j);

    cout << len[t-1][v2];
}