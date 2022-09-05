#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, T, c1, c2;
char A[100009], B[100009];

char diff (char c1, char c2)
{
    for (char c= 'a';c<='z';c++)
        if (c != c1 && c != c2) return c;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &T);
gets (A + 1), gets (B + 1);
for (int i=1; i<=N; i++)
    if (A[i] == B[i]) c1 ++;
    else c2 ++;

for (int x=0; x<=c1 && x<=T; x++)
    if (T - x <= c2 && c2 - (T - x) <= T - x)
    {
        int a1 = x, a, b, c;
        a = b = c2 - (T - x);
        c = T - x - a;
        if (a < 0 || b < 0 || c < 0) continue;
        for (int i=1; i<=N; i++)
        {
            if (A[i] == B[i])
            {
                if (a1 <= 0) printf ("%c", A[i]);
                else printf ("%c", diff (A[i], A[i])), a1 --;
            }
            else
            {
                if (a) printf ("%c", A[i]), a --;
                else
                if (b) printf ("%c", B[i]), b --;
                else
                if (c) printf ("%c", diff (A[i], B[i])), c --;
            }
        }
        return 0;
    }

printf ("-1\n");
return 0;
}