#include<bits/stdc++.h>

using namespace std;

int N, M, nr, a[10009], b[1009], ap[100009], ap1[100009], ap2[100009];
map < string, int > mp;
char sir[10009];

void Rd (int &x)
{
    scanf ("%s", sir);
    string curr = sir;
    if (mp.count (curr)) x = mp[curr];
    else mp[curr] = x = ++nr;
}

void Ans (bool cine)
{
    if (cine == 0) printf ("YES\n");
    else printf ("NO\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    Rd (a[i]), ap1[a[i]] = 1;
for (int i=1; i<=M; i++)
    Rd (b[i]), ap2[b[i]] = 1;
int mv = 1;
while (1)
{
    mv ^= 1;
    if (mv == 0)
    {
        ///muta primu si spune un cuvant pe care il are si alalalt
        int val = 0;
        for (int i=1; i<=N; i++)
            if (ap[a[i]] == 0 && ap2[a[i]] == 1) val = a[i];
        if (val != 0) ap[val] = 1;
        else
        {
            for (int i=1; i<=N; i++)
                if (ap[a[i]] == 0) val = a[i];
            if (val == 0) Ans (1);
            else ap[val] = 1;
        }
        continue;
    }
    int val = 0;
    for (int i=1; i<=M; i++)
        if (ap[b[i]] == 0 && ap1[b[i]] == 1) val = b[i];
    if (val != 0) ap[val] = 1;
    else
    {
        for (int i=1; i<=M; i++)
            if (ap[b[i]] == 0) val = b[i];
        if (val == 0) Ans (0);
        else ap[val] = 1;
    }
    continue;
}

return 0;
}