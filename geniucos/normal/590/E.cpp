#include<bits/stdc++.h>

using namespace std;

int N, st[759], dr[759], bg[759], l[759];
bool C[759], l_cov[759], r_cov[759];
bitset < 759 > ap[759];
char sir[10000009];
vector < int > v[759];

short id[10000009], last_id[10000009];
int Nr, R, urm[2][10000009], phi[10000009], pntr[759];

void BuildPhi ()
{
    int nr = 0, q[10000009];
    phi[0] = 0;
    for (int i=0; i<2; i++)
        if (urm[i][0] != 0)
            q[++nr] = urm[i][0], phi[q[nr]] = 0;
    for (int i=1; i<=nr; i++)
        for (int j=0; j<2; j++)
            if (urm[j][q[i]] != 0)
            {
                q[++nr] = urm[j][q[i]];
                int k = phi[q[i]];
                while (k && urm[j][k] == 0) k = phi[k];
                if (urm[j][k] != 0) k = urm[j][k];
                phi[q[nr]] = k;
                if (id[q[nr]] != 0) last_id[q[nr]] = id[q[nr]];
                else last_id[q[nr]] = last_id[phi[q[nr]]];
            }
}

void BuildGraph ()
{
    for (int i=1; i<=N; i++)
    {
        int q = 0;
        for (int j=bg[i]; j<bg[i] + l[i]; j++)
        {
            while (q && urm[sir[j]][q] == 0) q = phi[q];
            if (urm[sir[j]][q] != 0) q = urm[sir[j]][q];
            if (q == pntr[i]) q = phi[q];
            if (last_id[q] != 0) ap[last_id[q]][i] = 1;
        }
    }
    for (int i=1; i<=N; i++)
    {
        int q = pntr[i];
        while (q)
        {
            if (id[q] && id[q] != i) ap[id[q]][i] = 1;
            q = phi[q];
        }
    }
    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++)
            if (ap[i][k])
                ap[i] |= ap[k];
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (i != j && ap[i][j])
                v[i].push_back (j);//, printf ("%d %d\n", i, j);
}

bool pair_up (int nod)
{
    if (C[nod]) return 0;
    C[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (st[*it] == 0)
        {
            st[*it] = nod, dr[nod] = *it;
            return 1;
        }
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (pair_up (st[*it]))
        {
            st[*it] = nod, dr[nod] = *it;
            return 1;
        }
    return 0;
}

void MaxMatch ()
{
    bool ok = 1;
    while (ok)
    {
        ok = 0, memset (C, 0, sizeof (C));
        for (int i=1; i<=N; i++)
            if (dr[i] == 0) ok |= pair_up (i);
    }
    int ans = 0;
    for (int i=1; i<=N; i++)
        ans += (dr[i] == 0);
    printf ("%d\n", ans);
}

void vertex_cover (int nod)
{
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        if (r_cov[*it]) continue;
        r_cov[*it] = 1;
        if (st[*it]) l_cov[st[*it]] = 0, vertex_cover (st[*it]);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), bg[1] = 1, R = 0;
for (int i=1; i<=N; i++)
{
    gets (sir + bg[i]), l[i] = strlen (sir + bg[i]);
    int q = R;
    for (int j=bg[i]; j<bg[i] + l[i]; j++)
    {
        sir[j] -= 'a';
        if (urm[sir[j]][q] == 0) urm[sir[j]][q] = ++ Nr;
        q = urm[sir[j]][q];
    }
    bg[i + 1] = bg[i] + l[i], id[q] = i, pntr[i] = q;
}
BuildPhi ();
BuildGraph ();
MaxMatch ();
for (int i=1; i<=N; i++)
    l_cov[i] =(dr[i] != 0);
for (int i=1; i<=N; i++)
    if (!l_cov[i]) vertex_cover (i);
vector < int > ans;
for (int i=1; i<=N; i++)
    if (l_cov[i] + r_cov[i] == 0) ans.push_back (i);
//printf ("%d\n", ans.size ());
for (vector < int > :: iterator it = ans.begin (); it != ans.end (); it ++)
    printf ("%d ", *it);
printf ("\n");
return 0;
}