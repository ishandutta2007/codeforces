#include <iostream>
#include <fstream>
using namespace std;

int n, i;

int main()
{
    scanf ("%d", &n);
    if (n < 6)
    {
        printf ("-1\n");
    }
    else
    {
        printf ("1 2\n2 3\n2 4\n");
        for (i = 5; i <= n; i ++)
        {
            printf ("3 %d\n", i);
        }
    }
    for (i = 1; i < n; i ++)
    {
        printf ("%d %d\n", i, i + 1);
    }
    return 0;
}