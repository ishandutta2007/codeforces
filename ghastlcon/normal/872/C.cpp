#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() //2366.cpp
{
    int q, n;

    /*freopen("2366.in" , "r", stdin );
    freopen("2366.out", "w", stdout);*/

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d", &n);
        switch(n % 4)
        {
        case 0:
            printf("%d\n", n / 4);

            break;
        case 1:
            printf("%d\n", n <  9 ? -1 : 1 + (n - 4 - 4 - 1) / 4);

            break;
        case 2:
            printf("%d\n", n <  6 ? -1 : 1 + (n - 4     - 2) / 4);

            break;
        case 3:
            printf("%d\n", n < 12 ? -1 : 1 + 1 + (n - 4 - 4 - 4 - 1 - 2) / 4);

            break;
        default:
            printf("%% %% %% Monad, ASPE, Dic, JU");

            break;
        }
        
    }

    return 0;
}