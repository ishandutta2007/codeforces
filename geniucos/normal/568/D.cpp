#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int nr, N, K, ap[100009], last_N;
pair < int , int > ans[10];

struct line
{
    int a, b, c, init;
};
vector < line > v;

struct point
{
    long long a, b, c, d;
    ////a / b and c / d
    bool operator == (const point &other) const
    {
        return (1LL * a * other.b == 1LL * b * other.a && 1LL * c * other.d == 1LL * d * other.c);
    }
    bool operator < (const point &other) const
    {
        if (1LL * a * other.b == 1LL * b * other.a) return (1LL * c * other.d < 1LL * d * other.c);
        return (1LL * a * other.b < 1LL * b * other.a);
    }
};

bool OnLine (point p, line l)
{
    return ((long long) 1LL * l.a * p.a * p.d + 1LL * l.b * p.b * p.c + 1LL * l.c * p.b * p.d == 0LL);
}

bool Exist_Intersection (line p, line q)
{
    return (1LL * p.a * q.b != 1LL * p.b * q.a);
}

point Intersect (line p, line q)
{
    point ans;
    ans.c = (long long) 1LL * q.c * p.a - 1LL * q.a * p.c;
    ans.d = (long long) 1LL * p.b * q.a - 1LL * q.b * p.a;
    ans.a = (long long) 1LL * q.c * p.b - 1LL * q.b * p.c;
    ans.b = (long long) 1LL * p.a * q.b - 1LL * q.a * p.b;
    return ans;
}

void Push (int i, int j)
{
    ans[++nr] = make_pair (i, j);
}

void Pop ()
{
    nr --;
}

bool back (int pos, int K, vector < line > v)
{
    if (pos == v.size ()) return 1;
    if (K < 0) return 0;
    if (ap[pos]) return back (pos + 1, K, v);
    point I;
    for (int i=pos + 1; i<N; i++)
    {
        if (ap[i]) continue;
        if (Exist_Intersection (v[i], v[pos]) == 0) continue;
        I = Intersect (v[i], v[pos]);
        for (int j=pos; j<N; j++)
            if (OnLine (I, v[j]))
                ap[j] ++;
        Push (v[pos].init, v[i].init);
        if (back (pos + 1, K - 1, v) == 1) return 1;
        Pop ();
        for (int j=pos; j<N; j++)
            if (OnLine (I, v[j]))
                ap[j] --;
    }
    Push (v[pos].init, -1), ap[pos] ++;
    if (back (pos + 1, K - 1, v) == 1) return 1;
    Pop (), ap[pos] --;
    return 0;
}

bool solve (int K, vector < line > v)
{
    int N = v.size ();
    if (K >= N)
    {
        for (int i=0; i<N; i++)
            Push (v[i].init, -1);
        return 1;
    }
    if (K < 0) return 0;
    if (N <= K * K)
    {
        if (back (0, K, v)) return 1;
        return 0;
    }

    int M = K * K + 1, needed = K + 1;
    set < point > inters;
    for (int i=0; i<M; i++)
        for (int j=i + 1;j < M; j++)
        {
            if (Exist_Intersection (v[i], v[j]) == 0) continue;
            point curr = Intersect (v[i], v[j]);
            if (inters.count (curr)) continue;
            inters.insert (curr);
            int nr = 0;
            for (int p=i; p < M; p++)
                if (OnLine (curr, v[p]))
                    nr ++;
            if (nr >= needed)
            {
                vector < line > apel;
                for (int p=0; p<N; p++)
                    if (!OnLine (curr, v[p]))
                        apel.push_back (v[p]);
                Push (v[i].init, v[j].init);
                if (solve (K - 1, apel)) return 1;
                Pop ();
                return 0;
            }
        }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*printf ("100 1\n");
for (int i=0; i<100; i++)
    printf ("1 0 %d\n", i);
return 0;*/
scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
{
    line curr;
    scanf ("%d %d %d", &curr.a, &curr.b, &curr.c), curr.init = i;
    v.push_back (curr);
}

if (solve (K, v))
{
    printf ("YES\n");
    printf ("%d\n", nr);
    for (int i=1; i<=nr; i++)
        printf ("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
printf ("NO\n");

return 0;
}