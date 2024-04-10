#include<bits/stdc++.h>

using namespace std;

int N, ans[1009];
char sir[1009];

void solve (int pos, int type)
{
    if (pos == 0) return ;
    if (type)
    {
        ///I want it ascending
        if (sir[pos] == 1) solve (pos - 1, 1);
        else solve (pos - 1, 0), ans[pos] = 1;
        return ;
    }
    ///I want it descending
    if (sir[pos] == 0) solve (pos - 1, 0);
    else solve (pos - 1, 1), ans[pos] = 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    sir[i] -= 'a';
solve (N, 1);
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);
return 0;
}