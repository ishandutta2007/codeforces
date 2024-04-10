#include <bits/stdc++.h>

using namespace std;

const char* bus[6]={
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

char ans[6][27];

int main()
{
    int N;
    scanf("%d", &N);
    ans[1][26]=ans[4][26]=')';
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(bus[j][i]=='#' && N)
                N--, ans[j][i]='O';
            else
                ans[j][i]=bus[j][i];
        }
    }
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<((i==1 || i==4)?27:26); j++)
            putchar(ans[i][j]);
        putchar('\n');
    }
    return 0;
}