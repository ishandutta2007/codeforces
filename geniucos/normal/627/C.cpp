#include<bits/stdc++.h>

using namespace std;

int N, M, D;
long long ans;
map < int, int > C;
set < pair < int, int > > S;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &D, &N, &M), C[D] = 1e9 + 3;
for (int i=0; i<=M; i++)
{
    int x, c;
    if (i != 0) scanf ("%d %d", &x, &c);
    else x = c = 0;
    if (!C.count (x)) C[x] = c;
    else
    if (c < C[x]) C[x] = c;
    int y = x + N;
    if (y > D) y = D;
    if (!C.count (y)) C[y] = 1e9 + 3;
}
int lst = 0;
auto j = C.begin ();
S.insert (make_pair (C[0], 0));
for (map < int, int > :: iterator it = C.begin (); it != C.end (); it ++)
{
    if (it->first == 0) continue;
    while (j->first + N < it->first) S.erase (S.find (make_pair (j->second, j->first))), j ++;
    if (S.empty ())
    {
        printf ("-1\n");
        return 0;
    }
    pair < int, int > bst = *(S.begin ());
    if (bst.first > 1e9)
    {
        printf ("-1\n");
        return 0;
    }
    ans += 1LL * (it->first - lst) * bst.first, lst = it->first, S.insert (make_pair (it->second, it->first));
}
printf ("%I64d\n", ans);

return 0;
}