#include<bits/stdc++.h>

using namespace std;

int r, b, y;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &y, &b, &r);
y = min (y, b - 1);
y = min (y, r - 2);
printf ("%d\n", 3 * y + 3);

return 0;
}