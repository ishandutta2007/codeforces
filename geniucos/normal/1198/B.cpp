#include<bits/stdc++.h>

using namespace std;

int nodes, N, I, a[600009], ans[200009], pos[600009];
pair < int, int > initV[600009];
priority_queue < pair < int, int > > PQ;
vector < int > v[600009];

void print ()
{
    while (!PQ.empty ())
    {
        auto curr = PQ.top ();
        for (auto i : v[curr.second])
            if (pos[i] == curr.second)
                ans[i] = -curr.first;
        PQ.pop ();
    }
    for (int i=1; i<=N; i++)
        printf ("%d%c", ans[i], " \n"[i == N]);
}

void spill (int source, int &dest)
{
    if (v[source].size () < v[dest].size ())
    {
        for (auto i : v[source])
            if (pos[i] == source)
                pos[i] = dest, v[dest].push_back (i);
        vector < int >().swap (v[source]);
        //printf ("%d\n", v[source].capacity());
    }
    else
    {
        for (auto i : v[dest])
            if (pos[i] == dest)
                pos[i] = source, v[source].push_back (i);
        vector < int >().swap (v[dest]);
        dest = source;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &initV[i].first), initV[i].second = i;
sort (initV + 1, initV + N + 1);
for (int i=1; i<=N; i++)
{
    int j = i;
    while (j < N && initV[j + 1].first == initV[i].first)
        j ++;
    nodes ++, PQ.push (make_pair (-initV[i].first, nodes));
    for (int k=i; k<=j; k++)
        v[nodes].push_back (initV[k].second), pos[initV[k].second] = nodes;
    i = j;
}
int M;
scanf ("%d", &M);
while (M --)
{
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int i, newVal;
        scanf ("%d %d", &i, &newVal);
        pos[i] = ++nodes, PQ.push ({-newVal, nodes});
        v[nodes].push_back (i);
        continue;
    }
    int x, q = ++nodes; ///this one is for x
    scanf ("%d", &x);
    while (!PQ.empty ())
    {
        auto curr = PQ.top ();
        if (-curr.first >= x) break;
        PQ.pop ();
        spill (curr.second, q);
    }
    PQ.push ({-x, q});
}
print ();
return 0;
}