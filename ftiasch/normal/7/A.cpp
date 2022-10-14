// Codeforces Beta Round #7
// Problem A -- Kalevitch and Chess
#include <cstdio>

using namespace std;

char board[9][9];

int main()
{
    for(int i = 0; i < 8; ++ i)
        scanf("%s", board[i]);
    int cnt = 0;
    for(int i = 0; i < 8; ++ i)
    {
        int a = 1, b = 1;
        for(int j = 0; j < 8; ++ j)
        {
            if(board[i][j] == 'W')
                a = 0;
            if(board[j][i] == 'W')
                b = 0;
        }
        cnt += (a + b);
    }
    printf("%d\n", (cnt == 16)? 8: cnt);
    return 0;
}