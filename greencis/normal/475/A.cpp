#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int k;
string s[6];

int main()
{
    cin >> k;
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    if (k >= 1) s[1][1] = 'O';
    if (k >= 2) s[2][1] = 'O';
    if (k >= 3) s[3][1] = 'O';
    if (k >= 4) s[4][1] = 'O';

    if (k >= 5) s[1][3] = 'O';
    if (k >= 6) s[2][3] = 'O';
    if (k >= 7) s[4][3] = 'O';

    if (k >= 8) s[1][5] = 'O';
    if (k >= 9) s[2][5] = 'O';
    if (k >= 10) s[4][5] = 'O';

    if (k >= 11) s[1][7] = 'O';
    if (k >= 12) s[2][7] = 'O';
    if (k >= 13) s[4][7] = 'O';

    if (k >= 14) s[1][9] = 'O';
    if (k >= 15) s[2][9] = 'O';
    if (k >= 16) s[4][9] = 'O';

    if (k >= 17) s[1][11] = 'O';
    if (k >= 18) s[2][11] = 'O';
    if (k >= 19) s[4][11] = 'O';

    if (k >= 20) s[1][13] = 'O';
    if (k >= 21) s[2][13] = 'O';
    if (k >= 22) s[4][13] = 'O';

    if (k >= 23) s[1][15] = 'O';
    if (k >= 24) s[2][15] = 'O';
    if (k >= 25) s[4][15] = 'O';

    if (k >= 26) s[1][17] = 'O';
    if (k >= 27) s[2][17] = 'O';
    if (k >= 28) s[4][17] = 'O';

    if (k >= 29) s[1][19] = 'O';
    if (k >= 30) s[2][19] = 'O';
    if (k >= 31) s[4][19] = 'O';

    if (k >= 32) s[1][21] = 'O';
    if (k >= 33) s[2][21] = 'O';
    if (k >= 34) s[4][21] = 'O';

    for (int i = 0; i < 6; ++i)
        cout << s[i] << endl;

    return 0;
}