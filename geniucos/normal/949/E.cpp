#include<bits/stdc++.h>

using namespace std;

const int shift = 200000;
bool ap[400009];
vector < int > solve (int bit, vector < int > &v)
{
    int anyOdd = 0, mi = 1 << 30, ma = -mi;
    for (auto it : v)
        anyOdd |= (it & 1),
        mi = min (mi, it),
        ma = max (ma, it);
    if (mi == ma && mi == 0) return {};
    if (!anyOdd)
    {
        for (auto &it : v)
            it /= 2;
        return solve (bit + 1, v);
    }
    vector < int > ans;
    ans.resize (20);
    if (bit == 19) return ans;
    for (int i=-1; i<=1; i+=2)
    {
        vector < int > curr;
        for (auto it : v)
        {
            int val = it;
            if (it & 1) val -= i;
            val /= 2;
            if (ap[val + shift] == 0)
                curr.push_back (val), ap[val + shift] = 1;
        }
        for (auto it : curr)
            ap[it + shift] = 0;
        vector < int > potentialAns = solve (bit + 1, curr);
        potentialAns.push_back (i * (1 << bit));
        if (potentialAns.size () < ans.size ())
            ans = potentialAns;
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N;
scanf ("%d", &N);
vector < int > curr;
curr.resize (N);
for (int i=0; i<N; i++)
    scanf ("%d", &curr[i]);

vector < int > ans = solve (0, curr);
printf ("%d\n", ans.size ());
for (auto it : ans)
    printf ("%d ", it);
printf ("\n");

return 0;
}