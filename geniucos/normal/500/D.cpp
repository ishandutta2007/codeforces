#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, Q, sub[100009], x[100009], y[100009], d[100009], ap[100009];
double p[100009], sum;
vector < int > v[100009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

void dfs (int nod)
{
    ap[nod] = 1;
    sub[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)
        if (ap[*it] == 0)
        {
            dfs (*it);
            sub[nod] += sub[*it];
        }
}

long long comb2 (int N)
{
    return (long long)(1LL * N * (N - 1)) / 2;
}

long long comb3 (int N)
{
    return (long long)(1LL * N * (N - 1) * (N - 2)) / 6;
}

double prob_edge (int i)
{
    int A, B;
    if (sub[x[i]] > sub[y[i]])
        A = sub[y[i]] ;
    else A = sub[x[i]] ;
    B = N - A;
    long long ways = (long long)1LL * comb2 (A) * B + 1LL * comb2(B) * A;
    return (double) ways / comb3 (N);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    scanf ("%d %d %d", &x[i], &y[i], &d[i]);
    v[x[i]].push_back (y[i]);
    v[y[i]].push_back (x[i]);
}

dfs (1);

for (int i=1; i<N; i ++)
{
    p[i] = prob_edge (i);
    sum += (double) p[i] * d[i] * 2;
}

scanf ("%d", &Q);
while (Q)
{
    int r, w;
    Q --;
    scanf ("%d %d", &r, &w);
    sum -= (double) ((double)d[r] - w) * p[r] * 2;
    d[r] = w;
    printf ("%.10lf\n", sum);
}

return 0;
}