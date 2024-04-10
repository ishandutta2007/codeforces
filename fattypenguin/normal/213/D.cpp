#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define PB push_back
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const double CX[] =
{
    3.830127018922193,
    -3.601321235851749,
    0.466045194906253,
    10.411264148588986,
    12.490381056766580
};

const double CY[] =
{
    3.366025403784439,
    10.057331467373021,
    19.192786043799030,
    18.147501411122495,
    8.366025403784439
};


int main()
{
    int n;
    cin >> n;
    cout << (n-1)*4+5 << endl;
    for (int i = 0; i < 5; ++i)
        printf("%.12f %.12f\n", CX[i], CY[i]);
    double BX = CX[2]-CX[0], BY = CY[2]-CY[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < 5; ++j)
            printf("%.12f %.12f\n", CX[j]+BX, CY[j]+BY);
        BX += CX[2]-CX[0], BY += CY[2]-CY[0];
    }

    for (int i = 0; i < 5; ++i)
    {
        if (i) cout << " ";
        cout << i+1;
    }
    cout << endl;
    int cnt = 3;
    for (int i = 1; i < n; ++i)
    {
        cout << cnt;
        cnt += 3;
        for (int j = 0; j < 4; ++j)
            cout << " " << cnt++;
        cout << endl;
        cnt -= 3;
    }

    cout << 1;
    int cur = 3;
    for (int i = 0; i < n; ++i)
    {
        cout << " " << cur;
        cur += 4;
    }

    for (int i = 0; i < n-1; ++i)
    {
        cur -= 4;
        cout << " " << cur+2 << " " << cur-1 << " " << cur+1 << " " << cur-4;
    }
    cout << " 5 2 4 1" << endl;
    return 0;
}