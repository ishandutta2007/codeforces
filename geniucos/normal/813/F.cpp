#include<bits/stdc++.h>

using namespace std;

int N, M, t[100009], vol[100009], col[100009];

pair < int, int > getRelativeVal (int nod)
{
    int ans = 0;
    while (t[nod] != nod)
        ans ^= col[nod], nod = t[nod];
    return {nod, ans};
}

void moveBack (vector < pair < int, int > > &moves)
{
    for (auto it = moves.rbegin (); it != moves.rend (); it ++)
    {
        int x = it->first, y = it->second;
        vol[y] -= vol[x];
        t[x] = x, col[x] = 0;
    }
}

bool FAILED;
void solve (int st, int dr, vector < pair < pair < int, int >, pair < int, int > > > &allEdges)
{
    vector < pair < pair < int, int >, pair < int, int > > > v1, v2;
    vector < pair < int, int > > currentEdges;
    int mij = (st + dr) >> 1;
    for (auto it : allEdges)
    {
        if (it.second.first <= st && dr <= it.second.second) currentEdges.push_back (it.first);
        else
        {
            if (it.second.first <= mij) v1.push_back (it);
            if (mij < it.second.second) v2.push_back (it);
        }
    }
    vector < pair < int, int > > moves;
    for (auto it : currentEdges)
    {
        int x = it.first, y = it.second;
        pair < int, int > xx = getRelativeVal (x), yy = getRelativeVal (y);
        if (xx.first == yy.first)
        {
            if (xx.second == yy.second)
            {
                FAILED = 1;
                break;
            }
            continue;
        }
        if (vol[xx.first] < vol[yy.first])
        {
            t[xx.first] = yy.first;
            vol[yy.first] += vol[xx.first];
            col[xx.first] = (xx.second == yy.second);
            moves.push_back ({xx.first, yy.first});
        }
        else
        {
            t[yy.first] = xx.first;
            vol[xx.first] += vol[yy.first];
            col[yy.first] = (xx.second == yy.second);
            moves.push_back ({yy.first, xx.first});
        }
    }
    if (FAILED)
    {
        for (int i=st; i<=dr; i++)
            printf ("NO\n");
        moveBack (moves), FAILED = 0;
        return ;
    }
    if (st == dr)
        printf ("YES\n");
    else
        solve (st, mij, v1),
        solve (mij + 1, dr, v2);
    currentEdges.clear ();
    moveBack (moves);
}

void readAndSolve ()
{
    map < pair < int, int >, int > mp;
    vector < pair < pair < int, int >, pair < int, int > > > allEdges;
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=M; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        if (mp.count ({x, y}))
        {
            int j = mp[{x, y}];
            mp.erase (mp.find ({x, y}));
            allEdges.push_back ({{x, y}, {j, i - 1}});
        }
        else mp[{x, y}] = i;
    }
    for (auto it : mp)
        allEdges.push_back ({it.first, {it.second, M}});
    for (int i=1; i<=N; i++)
        t[i] = i, vol[i] = 1;
    solve (1, M, allEdges);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

readAndSolve ();

return 0;
}