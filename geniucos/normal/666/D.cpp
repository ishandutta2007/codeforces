#include<bits/stdc++.h>

using namespace std;

int inf = 1e9, a1, b1, a2, b2, a, b, T, x[10], y[10], bst, bst_t, howX, howY;

int dist (int a, int b, int x, int y)
{
    int d = inf;
    if (x == a) d = y - b;
    else
    if (y == b) d = x - a;
    if (d < 0) d = -d;
    return d;
}

int getL (int x1, int x2, int y1, int y2)
{
    int a[4], b[4], p[4], mini = inf;
    a[0] = a[1] = x1, a[2] = a[3] = x2;
    b[0] = b[3] = y1, b[1] = b[2] = y2;
    for (int i=0; i<4; i++)
        p[i] = i;
    do {
        int maxi = 0;
        for (int i=0; i<4; i++)
            maxi = max (maxi, dist (x[i], y[i], a[p[i]], b[p[i]]));
        if (maxi < mini) mini = maxi;
    }while (next_permutation (p, p + 4));
    return mini;
}

void Print (int x1, int x2, int y1, int y2)
{
    int a[4], b[4], p[4], mini = inf, ansx[4], ansy[4];
    a[0] = a[1] = x1, a[2] = a[3] = x2;
    b[0] = b[3] = y1, b[1] = b[2] = y2;
    for (int i=0; i<4; i++)
        p[i] = i;
    do {
        int maxi = 0;
        for (int i=0; i<4; i++)
            maxi = max (maxi, dist (x[i], y[i], a[p[i]], b[p[i]]));
        if (maxi < mini)
        {
            mini = maxi;
            for (int i=0; i<4; i++)
                ansx[i] = a[p[i]], ansy[i] = b[p[i]];
        }
    }while (next_permutation (p, p + 4));
    printf ("%d\n", mini);
    for (int i=0; i<4; i++)
        printf ("%d %d\n", ansx[i], ansy[i]);
}

int getLy (int x1, int x2, int y)
{
    int l = x1 - x2, ans = inf;
    if (l != 0) ans = min (ans, getL (x1, x2, y, y - l));
    if (l != 0) ans = min (ans, getL (x1, x2, y, y + l));
    return ans;
}

int getLx (int y1, int y2, int x)
{
    int l = y1 - y2, ans = inf;
    if (l != 0) ans = min (ans, getL (x, x + l, y1, y2));
    if (l != 0) ans = min (ans, getL (x, x - l, y1, y2));
    return ans;
}

void TernY (int st, int dr, int x1, int x2)
{
    if (dr - st <= 2)
    {
        int mini = inf;
        for (int y=st; y<=dr; y++)
        {
            int curr = getLy (x1, x2, y);
            if (curr < mini) mini = curr, howY = y;
        }
        return ;
    }
    int mid1 = st + (dr - st) / 3, mid2 = dr - (dr - st) / 3;
    int C1 = getLy (x1, x2, mid1), C2 = getLy (x1, x2, mid2);
    if (C1 < C2) TernY (st, mid2, x1, x2);
    else TernY (mid1, dr, x1, x2);
}

void TernX (int st, int dr, int y1, int y2)
{
    if (dr - st <= 2)
    {
        int mini = inf;
        for (int x=st; x<=dr; x++)
        {
            int curr = getLx (y1, y2, x);
            if (curr < mini) mini = curr, howX = x;
        }
        return ;
    }
    int mid1 = st + (dr - st) / 3, mid2 = dr - (dr - st) / 3;
    int C1 = getLx (y1, y2, mid1), C2 = getLx (y1, y2, mid2);
    if (C1 < C2) TernX (st, mid2, y1, y2);
    else TernX (mid1, dr, y1, y2);
}

pair < int, int > bestY (int x1, int x2)
{
    TernY (-1e8, 1e8, x1, x2);
    int cost = getLy (x1, x2, howY);
    return make_pair (cost, howY);
}

pair < int, int > bestX (int y1, int y2)
{
    TernX (-1e8, 1e8, y1, y2);
    int cost = getLx (y1, y2, howX);
    return make_pair (cost, howX);
}

void Update (bool type, int st, int dr, int coor, int val)
{
    if (val >= bst) return ;
    bst = val;
    if (type == 0) bst_t = 0, a1 = st, a2 = dr, b = coor;
    else bst_t = 1, b1 = st, b2 = dr, a = coor;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    for (int i=0; i<4; i++)
        scanf ("%d %d", &x[i], &y[i]);
    bst = inf;
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (x[i] < x[j])
            {
                for (int k=0; k<4; k++)
                {
                    int curr = getLy (x[i], x[j], y[k]);
                    Update (0, x[i], x[j], y[k], curr);
                }
                pair < int, int > curr = bestY (x[i], x[j]);
                Update (0, x[i], x[j], curr.second, curr.first);
            }
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (y[i] < y[j])
            {
                for (int k=0; k<4; k++)
                {
                    int curr = getLx (y[i], y[j], x[k]);
                    Update (1, y[i], y[j], x[k], curr);
                }
                pair < int, int > curr = bestX (y[i], y[j]);
                Update (1, y[i], y[j], curr.second, curr.first);
            }
    if (bst == inf) printf ("-1\n");
    else
    {
        int X1, Y1, X2, Y2;
        if (bst_t)
        {
            Y1 = b1, Y2 = b2;
            if (bst == getL (a, a - (b1 - b2), b1, b2)) X1 = a, X2 = a - (b1 - b2);
            else X1 = a, X2 = a + (b1 - b2);
        }
        else
        {
            X1 = a1, X2 = a2;
            if (bst == getL (a1, a2, b, b - (a1 - a2))) Y1 = b, Y2 = b - (a1 - a2);
            else Y1 = b, Y2 = b + (a1 - a2);
        }
        Print (X1, X2, Y1, Y2);
    }
}

return 0;
}