#include<bits/stdc++.h>

using namespace std;

int r;
priority_queue < pair < int, int > > PQ;

void Read ()
{
    int n;
    scanf ("%d %d", &n, &r);
    for (int i=1; i<=n; i++)
    {
        int st, dr;
        scanf ("%d %d", &st, &dr);
        if (st < 0) st = 0;
        if (st <= dr) PQ.push (make_pair (-dr, st));
    }
}

int Nodes = 1, ansAint, maxX = 1e9 + 3;
struct node_type
{
    int ad = 0, val = 0, l = 0, r = 0;
    void split ();
    void refresh ();
}aint[16000009];

void node_type::split ()
{
    if (l == 0) l = ++Nodes;
    if (r == 0) r = ++Nodes;
    if (ad)
        aint[l].val += ad, aint[l].ad += ad, aint[r].val += ad, aint[r].ad += ad, ad = 0;
}

void node_type::refresh ()
{
    val = max (aint[l].val, aint[r].val);
}

void update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        aint[nod].ad += val, aint[nod].val += val;
        return ;
    }
    aint[nod].split ();
    int mij = (st + dr) >> 1;
    if (x <= mij) update (aint[nod].l, st, mij, x, y, val);
    if (mij < y) update (aint[nod].r, mij + 1, dr, x, y, val);
    aint[nod].refresh ();
}

int FindFirstOccurence (int nod, int st, int dr, int val)
{
    if (aint[nod].val < val) return maxX + 1;
    if (st == dr) return st;
    int mij = (st + dr) >> 1;
    aint[nod].split ();
    if (aint[aint[nod].l].val >= val) return FindFirstOccurence (aint[nod].l, st, mij, val);
    return FindFirstOccurence (aint[nod].r, mij + 1, dr, val);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
int curr_x = -1, old_max = 0;
while (!PQ.empty ())
{
    pair < int, int > curr = PQ.top ();
    PQ.pop ();
    int x = -curr.first, y = curr.second;
    if (x < curr_x) continue;
    if (x > maxX) break;
    if (curr_x < x)
    {
        while (1)
        {
            int pos = FindFirstOccurence (1, 0, maxX, old_max + 1);
            if (pos + r > x)
            {
                update (1, 0, maxX, curr_x + 1, x, old_max);
                break;
            }
            ///de la pos + r la x o sa am old_max + 1
            if (pos + r - 1 > curr_x) update (1, 0, maxX, curr_x + 1, pos + r - 1, old_max);
            curr_x = max (curr_x, pos + r - 1), old_max ++;
        }
    }
    update (1, 0, maxX, y, x, +1), curr_x = x;
}
printf ("%d\n", aint[1].val);

return 0;
}