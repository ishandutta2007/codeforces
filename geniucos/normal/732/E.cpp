#include<bits/stdc++.h>

using namespace std;

int ans_1, ans_2, N, M, adap[200009], socket[200009];
pair < int, int > a[200009];
set < pair < int, int > > S;

int find_any (int st, int dr)
{
    set < pair < int, int > > :: iterator it = S.lower_bound (make_pair (st, 0));
    if (it != S.end () && it->first <= dr)
    {
        int pos = it->second;
        S.erase (it);
        return pos;
    }
    return -1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i].first), a[i].second = i;
sort (a + 1, a + N + 1);
for (int i=1; i<=M; i++)
{
    int val;
    scanf ("%d", &val), S.insert (make_pair (val, i));
}
for (int I=N; I>=1; I--)
{
    int i = a[I].second, x = a[I].first;
    for (int j=0; (1LL << j) * x - (1LL << j) + 1 <= 1e9 && j <= 31; j++)
    {
        int st = (1 << j) * (x - 1) + 1, dr;
        if ((long long) (1LL << j) + st - 1 > 1e9) dr = 1e9;
        else dr = st + (1 << j) - 1;
        int pos = find_any (st, dr);
        if (pos != -1)
        {
            adap[pos] = j, ans_2 += j, socket[i] = pos, ans_1 ++;
            break;
        }
    }
}
printf ("%d %d\n", ans_1, ans_2);
for (int i=1; i<=M; i++)
    printf ("%d ", adap[i]);
printf ("\n");
for (int i=1; i<=N; i++)
    printf ("%d ", socket[i]);
printf ("\n");
return 0;
}