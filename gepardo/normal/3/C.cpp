#include <iostream>

using namespace std;

enum byWin {wNONE, wFIRST, wSECOND, wDRAW, wWRONG};
enum byMove {mFIRST, mSECOND, mWRONG};
enum byResult {rmFIRST, rmSECOND, rwFIRST, rwSECOND, rDRAW, rWRONG};

const char* msg[6] = {"first", "second", "the first player won", "the second player won", "draw", "illegal"};

byResult table[5][3] =
{
    {rmFIRST, rmSECOND, rWRONG},
    {rWRONG, rwFIRST, rWRONG},
    {rwSECOND, rWRONG, rWRONG},
    {rDRAW, rDRAW, rWRONG},
    {rWRONG, rWRONG, rWRONG}
};


char getChar()
{
    char c = 0;
    while (c <= ' ') c = getchar();
    return c;
}

char q[3][3];

byMove getByMove()
{
    int xCnt = 0, oCnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (q[i][j] == 'X') xCnt++;
            if (q[i][j] == '0') oCnt++;
        }
    if (xCnt == oCnt) return mFIRST;
    if (xCnt == oCnt + 1) return mSECOND;
    return mWRONG;
}

byWin getTruncByWin()
{
    for (int i = 0; i < 3; i++) if (q[i][0] == 'X' && q[i][1] == 'X' && q[i][2] == 'X') return wFIRST;
    for (int i = 0; i < 3; i++) if (q[i][0] == '0' && q[i][1] == '0' && q[i][2] == '0') return wSECOND;
    for (int i = 0; i < 3; i++) if (q[0][i] == 'X' && q[1][i] == 'X' && q[2][i] == 'X') return wFIRST;
    for (int i = 0; i < 3; i++) if (q[0][i] == '0' && q[1][i] == '0' && q[2][i] == '0') return wSECOND;
    if (q[0][0] == 'X' && q[1][1] == 'X' && q[2][2] == 'X') return wFIRST;
    if (q[0][0] == '0' && q[1][1] == '0' && q[2][2] == '0') return wSECOND;
    if (q[2][0] == 'X' && q[1][1] == 'X' && q[0][2] == 'X') return wFIRST;
    if (q[2][0] == '0' && q[1][1] == '0' && q[0][2] == '0') return wSECOND;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (q[i][j] == '.') return wNONE;
    return wDRAW;
}

byWin getByWin()
{
    byWin w = getTruncByWin();
    if (w != wFIRST && w != wSECOND) return w;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            char pc = q[i][j];
            q[i][j] = '.';
            byWin nw  = getTruncByWin();
            q[i][j] = pc;
            if (nw == wNONE) return w;
        }
    return wWRONG;
}

int main()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            q[i][j] = getChar();
    cout << msg[table[getByWin()][getByMove()]];
}