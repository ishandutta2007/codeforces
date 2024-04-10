#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
char A[1000009], B[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (A + 1), n = strlen (A + 1);
gets (B + 1), m = strlen (B + 1);
reverse (A + 1, A + n + 1), reverse (B + 1, B + m + 1);
while (n > 1 && A[n] == '0') n --;
while (m > 1 && B[m] == '0') m --;
if (n < m)
{
    printf ("<\n");
    return 0;
}
if (n > m)
{
    printf (">\n");
    return 0;
}
for (int i=n; i>=1; i--)
    if (A[i] != B[i])
    {
        if (A[i] < B[i]) printf ("<\n");
        else printf (">\n");
        return 0;
    }
printf ("=\n");
return 0;
}