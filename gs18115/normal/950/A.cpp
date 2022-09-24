#include <iostream>
#include <fstream>
using namespace std;

int r, l, a;

int main()
{
    scanf ("%d%d%d", &r, &l, &a);
    if (r >= l + a)
    {
        printf ("%d", (l + a) * 2);
    }
    else if (l >= r + a)
    {
        printf ("%d", (r + a) * 2);
    }
    else
    {
        printf ("%d", (r + l + a) / 2 * 2);
    }
    return 0;
}