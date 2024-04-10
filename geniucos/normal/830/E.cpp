#include<bits/stdc++.h>

using namespace std;

int firstNode, secondNode, N, M, a[100009], b[100009], c[100009], ans[100009];
vector < int > v[100009];

int nr, stk[100009], ap[100009];
bool anyC;
void dfs (int nod, int tata)
{
    if (anyC) return ;
    if (v[nod].size () > 3)
    {
        anyC = 1;
        ans[nod] = 2;
        for (int i=0; i<4; i++)
            ans[v[nod][i]] = 1;
        return ;
    }
    else
    if (v[nod].size () == 3)
    {
        if (firstNode == -1) firstNode = nod;
        else
        if (secondNode == -1) secondNode = nod;
    }
    stk[++nr] = nod, ap[nod] = nr;
    for (auto it : v[nod])
        if (it != tata)
        {
            if (ap[it] == 0)
            {
                dfs (it, nod);
            }
            else
            {
                anyC = 1;
                for (int i=ap[it]; i<=nr; i++)
                    ans[stk[i]] = 1;
            }
        }
    nr --;
}

void df2 (int nod, int tata)
{
    stk[++nr] = nod;
    if (nod == secondNode)
    {
        for (int i=1; i<=nr; i++)
            ans[stk[i]] = 2;
    }
    for (auto it : v[nod])
        if (it != tata)
            df2 (it, nod);
    nr --;
}

void getPath (int &sz, int nod, int tata, int h[])
{
    sz = 1, h[1] = tata;
    while (1)
    {
        h[++sz] = nod;
        if (v[nod].size () == 1) return ;
        int aux = nod;
        nod = v[nod][0] ^ v[nod][1] ^ tata;
        tata = aux;
    }
}

void markOnPath (int sz, int h[], int S)
{
    int val = S / sz;
    for (int i=1; i<=sz; i++)
        ans[h[i]] = S, S -= val;
}

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int lcm (int a, int b)
{
    return a / gcd (a, b) * b;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    scanf ("%d %d", &N, &M), anyC = 0;
    while (M --)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v[x].push_back (y);
        v[y].push_back (x);
    }
    for (int i=1; i<=N; i++)
        if (ap[i] == 0)
        {
            firstNode = -1, secondNode = -1, dfs (i, 1);
            if (anyC) break;
            if (secondNode != -1)
            {
                ///need to traverse the path between these two special nodes, mark it with 2 and its 4 neighbors with 1
                df2 (firstNode, -1);
                anyC = 1;
                for (auto it : v[firstNode])
                    if (ans[it] == 0) ans[it] = 1;
                for (auto it : v[secondNode])
                    if (ans[it] == 0) ans[it] = 1;
                break;
            }
            if (firstNode != -1)
            {
                ///I could still try
                int p, q, r;
                getPath (p, v[firstNode][0], firstNode, a);
                getPath (q, v[firstNode][1], firstNode, b);
                getPath (r, v[firstNode][2], firstNode, c);
                if (1LL * p * q + 1LL * p * r + 1LL * q * r <= 1LL * p * q * r)
                {
                    ///a solution exists, but I should take care at the value that I choose for S, as it has to be up to 1e6
                    ///I'll choose i, j, k so that i<=p, j<=q, k<=r, 1/i+1/j+1/k<=1 and lcm (i, j, k)<=1e6
                    if (min (min (p, q), r) >= 3) p = q = r = 3;
                    else
                    {
                        int avg;
                        if (p == 2) avg = min (q, r);
                        else
                        if (q == 2) avg = min (p, r);
                        else avg = min (p, q);
                        if (avg > 3)
                        {
                            if (p != 2) p = 4;
                            if (q != 2) q = 4;
                            if (r != 2) r = 4;
                        }
                    }
                    int S = lcm (lcm (p, q), r);
                    markOnPath (p, a, S);
                    markOnPath (q, b, S);
                    markOnPath (r, c, S);
                    anyC = 1;
                    break;
                }
            }
        }
    if (anyC)
    {
        printf ("YES\n");
        for (int i=1; i<=N; i++)
            printf ("%d%c", ans[i], " \n"[i == N]);
    }
    else printf ("NO\n");

    for (int i=1; i<=N; i++)
        ap[i] = 0, v[i].clear (), ans[i] = 0;
}
return 0;
}