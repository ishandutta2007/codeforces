#include<bits/stdc++.h>

using namespace std;

int N, K, nr;
long long ans[100009];
pair < int, pair < int, bool > > ev[200009];
multiset < pair < int, bool > > S;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    ev[++nr] = make_pair (x - K, make_pair (y, 0));
    ev[++nr] = make_pair (x, make_pair (y, 1));
}
sort (ev + 1, ev + nr + 1), ev[0].first = ev[1].first - 1;
for (int i=1; i<=nr; i++)
{
    if (ev[i].first != ev[i - 1].first && !S.empty ())
    {
        int coef = ev[i].first - ev[i - 1].first, op = 0, lst_y;
        for (auto it = S.begin (); it != S.end (); it ++)
        {
            if (op) ans[op] += 1LL * (it->first - lst_y) * coef;
            if (it->second == 0) op ++;
            else op --;
            lst_y = it->first;
        }
    }
    int y = ev[i].second.first;
    if (ev[i].second.second == 0) S.insert (make_pair (y - K, 0)), S.insert (make_pair (y, 1));
    else S.erase (S.find (make_pair (y - K, 0))), S.erase (S.find (make_pair (y, 1)));
}
for (int i=1; i<=N; i++)
    printf ("%I64d ", ans[i]);
printf ("\n");
return 0;
}