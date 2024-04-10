#include<bits/stdc++.h>

using namespace std;

int N;
long long ans;
multiset < int > S;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai), ai -= i;
//    printf ("%d%c", ai, " \n"[i==N]);
    if (S.empty () || (*S.rbegin ()) <= ai) S.insert (ai);
    else
    {
        auto it = S.end (); it --;
        ans += (*it) - ai, S.erase (it), S.insert (ai), S.insert (ai);
    }
}
printf ("%I64d\n", ans);

return 0;
}