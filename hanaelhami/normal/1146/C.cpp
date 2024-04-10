// LOL
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
mt19937 Rnd(time(0));
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        int k1 = n >> 1;
        int k2 = n - k1;
        int Mx = 0;
        for (int _ = 0; _ < 7; _ ++)
        {
            vector < int > vec, vec2;
            for (int i = 0; i < n; i++)
            {
                if (i & (1 << _))
                    vec.pb(i);
                else
                    vec2.pb(i);
            }
            if (vec.size() && vec2.size())
            {
                printf("%d %d ", (int)vec.size(), (int)vec2.size());
                for (int id : vec)
                    printf("%d ", id + 1);
                for (int id : vec2)
                    printf("%d ", id + 1);
                printf("\n"); fflush(stdout);
                int dist; scanf("%d", &dist);
                Mx = max(Mx, dist);
            }
        }
        printf("-1 %d\n", Mx);
        fflush(stdout);
    }
    return (0);
}