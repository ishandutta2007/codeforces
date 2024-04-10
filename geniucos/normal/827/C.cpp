#include<bits/stdc++.h>

using namespace std;

int aibs, N, lin[4][15], aib[41][100009], where[100009][11];
char sir[100009];

void U (int lin, int pos, int val) {while (pos <= N) aib[lin][pos] += val, pos += pos - (pos & (pos - 1));}
int Q (int lin, int pos) {int sum = 0; while (pos) sum += aib[lin][pos], pos &= pos - 1; return sum;}
int QLR (int lin, int l, int r) {return Q (lin, r) - Q (lin, l - 1);}

int code (char c)
{
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C') return 2;
    return 3;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s\n", sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    sir[i] = code (sir[i]);
for (int i=1; i<=10; i++)
{
    int currSz = 0;
    for (int r=0; r<i; r++)
        for (int j=r; j<=N; j+=i)
            if (j > 0)
                where[j][i] = ++currSz;
}
for (int val=0; val<4; val++)
    for (int sz=1; sz<=10; sz++)
    {
        lin[val][sz] = ++aibs;
        for (int i=1; i<=N; i++)
            if (sir[i] == val)
                U (aibs, where[i][sz], +1);
    }
int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    int type;
    scanf ("%d ", &type);
    if (type == 1)
    {
        int P;
        char c;
        scanf ("%d %c\n", &P, &c), c = code (c);
        for (int sz=1; sz<=10; sz++)
            U (lin[sir[P]][sz], where[P][sz], -1);
        sir[P] = c;
        for (int sz=1; sz<=10; sz++)
            U (lin[sir[P]][sz], where[P][sz], +1);
        continue;
    }
    int L, R, sz, ans = 0;
    char s[20];
    scanf ("%d %d %s\n", &L, &R, s + 1), sz = strlen (s + 1);
    for (int i=1; i<=sz && L <= R; i++, L ++)
    {
        s[i] = code (s[i]);
        int rightEnd = R;
        while (rightEnd % sz != L % sz) rightEnd --;
        ans += QLR (lin[s[i]][sz], where[L][sz], where[rightEnd][sz]);
    }
    printf ("%d\n", ans);
}
return 0;
}