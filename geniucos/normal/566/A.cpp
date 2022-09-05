#include<bits/stdc++.h>

using namespace std;

int N, sol;
string a[100009], b[100009];
vector < pair < int, int > > ans;

struct nod
{
    nod *urm[26];
    vector < int > a, b;
    nod ()
    {
        memset (urm, 0, sizeof (urm));
        a.clear (), b.clear ();
    }
}*R = new nod;

void Push (string &s, int val)
{
    nod *q = R;
    for (auto it = s.begin (); it != s.end (); it ++)
    {
        int i = (*it) - 'a';
        if (q->urm[i] == 0) q->urm[i] = new nod;
        q = q->urm[i];
    }
    if (val > 0) q->a.push_back (val);
    else q->b.push_back (-val);
}

void dfs (nod *&q, nod *&t)
{
    for (int i=0; i<26; i++)
        if (q->urm[i] != 0)
            dfs (q->urm[i], q);
    while ((!q->a.empty ()) && (!q->b.empty ()))
    {
        ans.push_back (make_pair (q->a[q->a.size () - 1], q->b[q->b.size () - 1]));
        q->a.erase (q->a.begin () + q->a.size () - 1), q->b.erase (q->b.begin () + q->b.size () - 1);
    }
    for (auto it = q->a.begin (); it != q->a.end (); it ++)
        t->a.push_back (*it);
    for (auto it = q->b.begin (); it != q->b.end (); it ++)
        t->b.push_back (*it);
}

void add_to_sol (int i, int j)
{
    for (int k=0; k<a[i].size () && k<b[j].size (); k++)
        if (a[i][k] != b[j][k]) break;
        else sol ++;
}

int main ()
{
//freopen ("input", "r", stdin);
//ifstream cin ("input");
//freopen ("output", "w", stdout);

cin >> N;
for (int i=1; i<=N; i++)
    cin >> a[i], Push (a[i], i);
for (int i=1; i<=N; i++)
    cin >> b[i], Push (b[i], -i);
dfs (R, R);
for (auto it = ans.begin (); it != ans.end (); it ++)
    add_to_sol (it->first, it->second);
printf ("%d\n", sol);
for (auto it = ans.begin (); it != ans.end (); it ++)
    printf ("%d %d\n", it->first, it->second);
return 0;
}