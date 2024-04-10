#include<bits/stdc++.h>

using namespace std;

int Q;
map < long long, long long > mp;

vector < long long > get_path (long long x, long long y)
{
    vector < long long > ans;
    while (x != y)
    {
        if (x > y) ans.push_back (x), x /= 2;
        else ans.push_back (y), y /= 2;
    }
    return ans;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &Q);
while (Q --)
{
    int type;
    long long u, v;
    scanf ("%d %I64d %I64d", &type, &u, &v);
    vector < long long > path = get_path (u, v);
    if (type == 1)
    {
        int ad;
        scanf ("%d", &ad);
        for (auto it = path.begin (); it != path.end (); it ++)
            mp[*it] += ad;
    }
    else
    {
        long long ans = 0;
        for (auto it = path.begin (); it != path.end (); it ++)
            ans += mp[*it];
        printf ("%I64d\n", ans);
    }
}

return 0;
}