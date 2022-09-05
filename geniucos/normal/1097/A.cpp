#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

char nada, c1, c2, x, y;
bool ans = 0;
scanf ("%c%c", &c1, &c2);
for (int i=1; i<=5; i++)
{
    scanf ("%c%c%c", &nada, &x, &y);
    if (x == c1 || y == c2)
        ans = 1;
}
if (ans) printf ("YES\n");
else printf ("NO\n");
return 0;
}