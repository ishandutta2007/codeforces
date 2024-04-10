#include<bits/stdc++.h>

using namespace std;

int N, A, B, K, sz, nr, ans[200009];
char sir[200009];
priority_queue < pair < int, pair < int, int > > > PQ;

void ad (int st, int dr)
{
    if (dr - st + 1 >= B) PQ.push (make_pair (dr - st + 1, make_pair (st, dr))), sz += (dr - st + 1) / B;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d\n", &N, &A, &B, &K);
gets (sir + 1);
for (int i=1; i<=N; i++)
    if (sir[i] == '0')
    {
        int j = i;
        for (j=i; j<=N; j++)
            if (sir[j] != '0') break;
        j --;
        ad (i, j);
        i = j;
    }
while (!PQ.empty () && sz >= A)
{
    pair < int, pair < int, int > > curr = PQ.top ();
    PQ.pop ();
    int st = curr.second.first, dr = curr.second.second, mij = st + B - 1;
    ans[++nr] = mij, sz -= (dr - st + 1) / B;
    ad (mij + 1, dr);
}
printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}