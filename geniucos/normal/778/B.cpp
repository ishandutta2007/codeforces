#include<bits/stdc++.h>

using namespace std;

int N, M, ma[1009], mi[1009], A[5009], x[5009], y[5009], tip[5009];
map < string, int > mp;
char aa[20], bb[1009], cc[20];
bitset < 1005 > val[5009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
mp["?"] = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%s := ", aa);
    string a = aa;
    mp[a] = i;
    scanf ("%s", bb);
    if (bb[0] == '0' || bb[0] == '1')
    {
        tip[i] = 3;
        for (int j=0; j<M; j++)
            val[i][j] = bb[j] - '0';
        continue;
    }
    x[i] = mp[bb];
    char c1, c2, c3;
    scanf (" %c", &c1);
    if (c1 == 'A') scanf ("%c%c ", &c2, &c3), tip[i] = 0;
    else
    if (c1 == 'O') scanf ("%c ", &c2), tip[i] = 1;
    else scanf ("%c%c ", &c2, &c3), tip[i] = 2;
    scanf ("%s", cc), y[i] = mp[cc];
}
/*for (int i=1; i<=N; i++)
{
    printf ("%d %d %d   ", tip[i], x[i], y[i]);
    for (int j=0; j<M; j++)
        if (val[i][j] == 1) printf ("1");
        else printf ("0");
    printf ("\n");
}*/
for (int bit = 0; bit < M; bit ++)
{
    int maxi = -1, mini = N + 10, hw_mi = -1, hw_mx = -1;
    for (int strt = 0; strt < 2; strt ++)
    {
        int curr = 0;
        A[0] = strt;
        for (int i=1; i<=N; i++)
        {
            if (tip[i] == 3) A[i] = val[i][bit];
            else
            if (tip[i] == 0) A[i] = A[x[i]] & A[y[i]];
            else
            if (tip[i] == 1) A[i] = A[x[i]] | A[y[i]];
            else A[i] = A[x[i]] ^ A[y[i]];
            curr += A[i];
        }
        if (curr > maxi) maxi = curr, hw_mx = strt;
        if (curr < mini) mini = curr, hw_mi = strt;
    }
    ma[bit] = hw_mx, mi[bit] = hw_mi;
}
for (int i=0; i<M; i++)
    printf ("%d", mi[i]);
printf ("\n");
for (int i=0; i<M; i++)
    printf ("%d", ma[i]);
printf ("\n");

return 0;
}