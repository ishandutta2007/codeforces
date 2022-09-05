#include<bits/stdc++.h>

using namespace std;

bool ap[300];
char sir[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int ans = 0, N;
for (char c = '1'; c <= '9'; c += 2)
    ap[c] = 1;
ap['a'] = ap['e'] = ap['i'] = ap['o'] = ap['u'] = 1;
gets (sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    ans += ap[sir[i]];
printf ("%d\n", ans);

return 0;
}