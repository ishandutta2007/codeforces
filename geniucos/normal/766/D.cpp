#include<bits/stdc++.h>

using namespace std;

int N, M, Q, col[100009], t[100009];
char irrelevantString[23];
map < string, int > mp;

int tata (int x)
{
    if (t[x] == x) return x;
    int val = tata (t[x]);
    col[x] ^= col[t[x]], t[x] = val;
    return val;
}

void unite (int x, int y, int val)
{
    if (tata (x) == tata (y))
    {
        if (val != (col[x] ^ col[y])) printf ("NO\n");
        else printf ("YES\n");
        return ;
    }
    printf ("YES\n");
    int tx = tata (x), ty = tata (y);
    t[tx] = ty;
    col[tx] = val ^ col[x] ^ col[y];
}

int ReadString ()
{
    scanf ("%s", irrelevantString);
    return mp[irrelevantString];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &Q);
for (int i=1; i<=N; i++)
    scanf ("%s", irrelevantString), mp[irrelevantString] = i, t[i] = i, col[i] = 0;
for (int i=1; i<=M; i++)
{
    int type = 0, x, y;
    scanf ("%d ", &type), x = ReadString (), y = ReadString ();
    unite (x, y, type - 1);
}
for (int i=1; i<=Q; i++)
{
    int x, y;
    x = ReadString (), y = ReadString ();
    if (tata (x) != tata (y))
    {
        printf ("3\n");
        continue;
    }
    printf ("%d\n", 2 - (col[x] == col[y]));
}
return 0;
}