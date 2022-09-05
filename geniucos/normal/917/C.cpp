#include<bits/stdc++.h>

using namespace std;

int c[20], nr, N, K, X, Q, lg[1030], realMsk[1030], code[1030];
const long long INF = 1LL << 60;
long long old[218], currDp[218], dist[30][218][218];
map < int, int > mp;
pair < int, int > stone[30];

void buildMatrices ()
{
    for (int i=0; i<K; i++)
        lg[1 << i] = i;
    for (int msk = 0; msk < (1 << K); msk ++)
    {
        int cnt = 0;
        for (int i=0; i<K; i++)
            if (msk & (1 << i))
                cnt ++;
        if (cnt == X)
            realMsk[++nr] = msk, code[msk] = nr;
    }
    for (int i=1; i<=nr; i++)
        for (int j=1; j<=nr; j++)
            dist[0][i][j] = -1;
    for (int i=1; i<=nr; i++)
    {
        if (realMsk[i] & 1)
        {
            int aux = realMsk[i] >> 1;
            for (int j=1; j<=K; j++)
                if (aux & (1 << (j - 1))) ;
                else dist[0][i][code[aux | (1 << (j - 1))]] = c[j];
        }
        else dist[0][i][code[realMsk[i] >> 1]] = 0;
    }
    for (int i=1; (1 << i) <= N; i++)
    {
        for (int j=1; j<=nr; j++)
            for (int k=1; k<=nr; k++)
                dist[i][j][k] = -1;
        for (int j=1; j<=nr; j++)
            for (int k=1; k<=nr; k++)
                if (dist[i - 1][j][k] != -1)
                    for (int p=1; p<=nr; p++)
                        if (dist[i - 1][k][p] != -1 && (dist[i][j][p] == -1 || dist[i - 1][j][k] + dist[i - 1][k][p] < dist[i][j][p]))
                            dist[i][j][p] = dist[i - 1][j][k] + dist[i - 1][k][p];
    }
    currDp[1] = 0;
    for (int i=2; i<=nr; i++)
        currDp[i] = INF;
}

void advance (int bit)
{
    memcpy (old, currDp, sizeof (currDp));
    for (int i=1; i<=nr; i++)
    {
        currDp[i] = INF;
        for (int j=1; j<=nr; j++)
            if (dist[bit][j][i] != -1 && old[j] + dist[bit][j][i] < currDp[i])
                currDp[i] = old[j] + dist[bit][j][i];
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &X, &K, &N, &Q);
if (N == X)
{
    printf ("0\n");
    return 0;
}
for (int i=1; i<=K; i++)
    scanf ("%d", &c[i]);
buildMatrices ();
for (int i=1; i<=Q; i++)
    scanf ("%d %d", &stone[i].first, &stone[i].second);
sort (stone + 1, stone + Q + 1);
if (stone[Q].first < N)
    stone[++Q] = {N, 0};
stone[++Q] = {N + K, 0};
for (int i=1; i<=Q; i++)
    mp[stone[i].first] = stone[i].second;
int lst = K;
long long ans = INF;
for (int obst = 1; obst <= Q; obst ++)
{
    int dt = stone[obst].first - 1 - lst;
    if (dt > 0)
    {
        for (int i=0; (1 << i) <= dt; i++)
            if (dt & (1 << i))
                advance (i);
        lst += dt;
    }
    int obst2 = obst;
    while (obst2 < Q && stone[obst2 + 1].first - stone[obst].first <= K + 2)
        obst2 ++;
    for (int currX = lst + 1; currX <= stone[obst2].first + K; currX ++)
    {
        memcpy (old, currDp, sizeof (currDp));
        for (int i=1; i<=nr; i++)
            currDp[i] = INF;
        for (int i=1; i<=nr; i++)
            for (int j=1; j<=nr; j++)
                if (dist[0][i][j] == 0 && old[i] + dist[0][i][j] < currDp[j])
                    currDp[j] = old[i] + dist[0][i][j];
        for (int i=1; i<=nr; i++)
            for (int j=1; j<=nr; j++)
                if (dist[0][i][j] > 0)
                {
                    int pos = lg[realMsk[j] ^ (realMsk[i] >> 1)];
                    ///bitul K - 1 e la currX acu
                    ///bitul 0 e la currX - (K - 1)
                    ///bitul pos e la currX - (K - 1) + pos
                    pos += currX - (K - 1);
                    long long curr = 0;
                    if (mp.count (pos))
                        curr = mp[pos];
                    curr += dist[0][i][j];
                    if (old[i] + curr < currDp[j])
                        currDp[j] = old[i] + curr;
                }
        lst = currX;
        if (lst >= N)
        {
            int aux = 0;
            bool ok = 1;
            for (int i=N - X + 1; i<=N; i++)
            {
                int pos = i - (lst - (K - 1));
                if (pos >= K || pos < 0) ok = 0;
                else aux |= 1 << pos;
            }
            if (ok && currDp[code[aux]] < ans)
                ans = currDp[code[aux]];
        }
    }
    ///
    obst = obst2;
}
printf ("%I64d\n", ans);
return 0;
}