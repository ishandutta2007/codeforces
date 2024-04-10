#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int n;

int rj[30] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401, 0, 0, 0, 0};

int main()
{
    cin >> n;
    int x;
    int maska, sup;
    for(int i = 1; i <= 25; i++)
    {
        maska = (1<<i) - 1;

    }
    REP(i, 0, n)
    {
        scanf("%d", &x);
        int pot = 0;
        bool jao = 1;
        while(x)
        {
            if(!(x & 1)) jao = 0;
            x /= 2;
            pot++;
        }
        if(!jao) printf("%d\n", (1<<pot) - 1);
        else printf("%d\n", rj[pot]);
    }
    return 0;
}