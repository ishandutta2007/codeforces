#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7, N, sol, tt[40];
bool ap[1209][1209];
vector < pair < pair < int, int >, int > > v, h;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void add (int i, int j)
{
    if (ap[i][j] == 0) ap[i][j] = 1, sol ++;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
v.push_back ({{600, 600}, 0}), ap[600][600] = 1, sol = 1;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &tt[i]), h.clear ();
    for (auto it = v.begin (); it != v.end (); it ++)
    {
        int x = it->first.first, y = it->first.second, z = it->second;
        for (int dir = -1; dir <= 1; dir += 2)
        {
            if (i == 1) dir = 0, tt[1] --;
            int t = (z + dir) % 8;
            if (t < 0) t += 8;
            int Steps = tt[i];
            int a = x, b = y;
            while (Steps --)
                a += dx[t], b += dy[t], add (a, b);
            h.push_back ({{a, b}, t});
            if (i == 1) break;
        }
    }
    sort (h.begin (), h.end ());
    h.erase (unique (h.begin (), h.end ()), h.end ());
    v = h;
/*    for (auto it = h.begin (); it != h.end (); it ++)
        printf ("(%d, %d)%d\n", it->first.first, it->first.second, it->second);
    printf ("\n");
    printf ("%d\n\n", sol);*/
}
printf ("%d\n", sol);
return 0;
}