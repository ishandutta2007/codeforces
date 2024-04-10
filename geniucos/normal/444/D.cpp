#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<unordered_map>
#include<string>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int sqr, N, M, ans[100009], ap[100009], prec[100009], nxt[100009];
char sir[50009];
string A[100009], B[100009];

unordered_map < string , vector < int > > mp, queries;
unordered_map < string , int > sol;
vector < int > v1, v2, p_q;

void Try (int i, int val)
{
    if (val < ans[i])
        ans[i] = val;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1);
N = strlen (sir + 1);
sqr = 800;

for (int i=1; i<=N; i++)
{
    string curr;
    for (int j=i; j <= i + 3 && j <= N; j++)
    {
        curr += (char) sir[j];
        mp[curr].push_back (i);
    }
}

scanf ("%d\n", &M);
for (int i=1; i<=M; i++)
{
    char s1[10], s2[10];
    scanf ("%s %s\n", s1, s2);
    string a = s1, b = s2;
    if (a == b)
    {
        if (mp.count (a)) ans[i] = a.length ();
        else ans[i] = -1;
        continue;
    }
    if (!mp.count (a) || !mp.count (b))
    {
        ans[i] = -1;
        continue;
    }
    v1 = mp[a], v2 = mp[b];
    ans[i] = N + 5;
    if (v1.size () <= sqr && v2.size () <= sqr)
    {
        int k = 0;
        for (int j=0; j<v2.size (); j++)
        {
            while (v1[k] < v2[j] && k < v1.size ()) k ++;
            if (k < v1.size ()) Try (i, max (v1[k] + (int)a.length () - 1, v2[j] + (int)b.length () - 1) - v2[j] + 1);
            if (k - 1 >= 0) Try (i, max (v2[j] + (int)b.length () - 1, v1[k-1] + (int)a.length () - 1) - v1[k-1] + 1);
        }
        continue;
    }
    A[i] = a, B[i] = b;
    if (v1.size () > sqr)
    {
        queries[A[i]].push_back (i);
        continue;
    }
    queries[B[i]].push_back (-i);
}

for (unordered_map < string , vector < int > > :: iterator it = queries.begin (); it != queries.end (); it ++)
{
    string a = it->first;
    p_q = it->second;
//    printf ("%s\n", a.c_str ());
  //  return 0;
    for (vector < int > :: iterator it2 = p_q.begin (); it2 != p_q.end (); it2 ++)
    {
        if (*it2 > 0) sol[B[*it2]] = 2 * N;
        else sol[A[-*it2]] = 2 * N;
    }

    for (int i=1; i<=N; i++)
        ap[i] = 0;
    v1 = mp[a];
    for (vector < int > :: iterator it2 = v1.begin (); it2 != v1.end (); it2 ++)
        ap[*it2] = 1;

    for (int i=1; i<=N; i++)
    {
        if (ap[i]) prec[i] = i;
        else prec[i] = prec[i-1];
    }

    for (int i=N; i>=1; i--)
    {
        if (ap[i]) nxt[i] = i;
        else nxt[i] = nxt[i+1];
    }

    for (int i=1; i<=N; i++)
    {
        string curr;
        for (int j=i; j<=i+3 && j<=N; j++)
        {
            curr += sir[j];
            if (!sol.count (curr)) continue;
            int cost = 2 * N;
            if (prec[i] != 0) cost = max (j, prec[i] + (int)a.length () - 1) - prec[i] + 1;
            if (nxt[i] != 0) cost = min (cost, max (nxt[i] + (int)a.length () - 1, j) - i + 1);
            if (cost < sol[curr])
                sol[curr] = cost;
        }
    }

    for (vector < int > :: iterator it2 = p_q.begin (); it2 != p_q.end (); it2 ++)
    {
        if (*it2 > 0) ans[*it2] = sol[B[*it2]];
        else ans[-*it2] = sol[A[-*it2]];
    }
    sol.clear ();
}

for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}