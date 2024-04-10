#include<bits/stdc++.h>

using namespace std;

int N;
typedef pair < int, int > op;
pair < vector < op >, vector < op > > path1, path2;

class triangulation
{
public:
    triangulation ()
    {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                third[i][j][0] = third[i][j][1] = -1;
        for (int i=0; i<N; i++)
            v[i].clear ();
    }

    void read ()
    {
        ///triangulation (); why can't I call it?
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                third[i][j][0] = third[i][j][1] = -1;
        for (int i=0; i<N; i++)
            v[i].clear ();
        for (int i=1; i<=N - 3; i++)
        {
            int x, y;
            scanf ("%d %d", &x, &y);
            x --, y --;
            addEdge (x, y);
        }
    }

    pair < vector < op >, vector < op > > toAndFrom ()
    {
        for (int i=0; i<N; i++)
            addEdge (i, (i + 1) % N);
        for (int i=0; i<N; i++)
        {
//            currComparator = i;
            sort (v[i].begin (), v[i].end (), [ &i ] (int x, int y) {
                bool tx = (x < i), ty = (y < i);
                if (tx != ty) return (tx < ty);
                return (x < y);
            });
            for (int j=0; j + 1 < v[i].size (); j++)
                addTriangle (i, v[i][j], v[i][j + 1]);
        }
        vector < op > to, from;
        for (int j=0; j + 1 < v[0].size (); j++)
            solve (v[0][j], v[0][j + 1], to, from);
        reverse (from.begin (), from.end ());
        return {to, from};
    }

    void solve (int l, int r, vector < op > &to, vector < op > &from)
    {
        if (third[l][r][1] == -1) return ;
        to.push_back ({l, r});
        op curr = simulateOp (l, r);
        from.push_back (curr);
        if (curr.first != 0) swap (curr.first, curr.second);
        solve (l, curr.second, to, from);
        solve (curr.second, r, to, from);
    }

private:
    int third[1009][1009][2];
    const int currComparator = 3;
    vector < int > v[1009];

    bool cmp (int x, int y) const
    {
        bool tx = (x < currComparator), ty = (y < currComparator);
        if (tx != ty) return (tx < ty);
        return (x < y);
    }

    void addEdge (int x, int y)
    {
        v[x].push_back (y);
        v[y].push_back (x);
    }

    void addVal (int l, int r, int th)
    {
        if (third[l][r][0] == -1) third[l][r][0] = th;
        else
        if (third[l][r][0] != th) third[l][r][1] = th;
    }

    void delVal (int l, int r, int th)
    {
        if (third[l][r][0] == th) swap (third[l][r][0], third[l][r][1]);
        if (third[l][r][1] == th) third[l][r][1] = -1;
    }

    void addTriangle (int a, int b, int c)
    {
//        printf ("+(%d, %d, %d)\n", a, b, c);
        addVal (a, b, c), addVal (b, a, c);
        addVal (a, c, b), addVal (c, a, b);
        addVal (b, c, a), addVal (c, b, a);
    }

    void delTriangle (int a, int b, int c)
    {
        delVal (a, b, c), delVal (b, a, c);
        delVal (a, c, b), delVal (c, a, b);
        delVal (b, c, a), delVal (c, b, a);
    }

    op simulateOp (int x, int y)
    {
        int z = third[x][y][0], t = third[x][y][1];
        delTriangle (z, x, y);
        delTriangle (t, x, y);
        addTriangle (x, z, t);
        addTriangle (y, z, t);
        return {z, t};
    }
}t1, t2;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
t1.read (), t2.read ();
path1 = t1.toAndFrom ();
path2 = t2.toAndFrom ();
printf ("%d\n", path1.first.size () + path2.second.size ());
for (auto it : path1.first)
    printf ("%d %d\n", it.first + 1, it.second + 1);
for (auto it : path2.second)
    printf ("%d %d\n", it.first + 1, it.second + 1);
return 0;
}