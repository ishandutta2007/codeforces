#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<string>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, nr, a[500009], st[500009], dr[500009], ap[500009];
long long sol;
queue < int > cc;

void del (int i)
{
    int a = st[i], b = dr[i];
    dr[a] = b, st[b] = a;
}

void Try (int i)
{
    if (ap[i]) return;
    if (a[i] <= a[st[i]] && a[i] <= a[dr[i]])
        cc.push (i), ap[i] = 1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), dr[0] = 1, st[N + 1] = N;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    dr[i] = i + 1;
    st[i] = i - 1;
}

for (int i=1; i<=N; i++)
    Try (i);

while (!cc.empty ())
{
    int i = cc.front ();
    cc.pop ();
    sol += min (a[st[i]], a[dr[i]]), del (i);
    Try (st[i]);
    Try (dr[i]);
}

for (int i=dr[0]; i!=N + 1; i = dr[i])
    sol += min (a[st[i]], a[dr[i]]);

printf ("%I64d\n", sol);
return 0;
}