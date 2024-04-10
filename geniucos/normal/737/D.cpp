#include<bits/stdc++.h>

using namespace std;

int N, a[4002], s[4002];
int dp2[4002][140][75][2];
bitset < 4002 > dej[140][75][2];

int sum (int st, int dr) {return s[dr] - s[st - 1];}

bool mrk (int i, int j, int k, int p)
{
    bool old = dej[j - i + 68][k][p][i];
    dej[j - i + 68][k][p][i] = 1;
    return old;
}

int& adrs (int i, int j, int k, int p) {return dp2[i][j - i + 68][k][p];}

int dp (int i, int j, int k, int p)
{
    if (i + j + k > N) return 0;
    int &val = adrs (i, j, k, p);
    if (mrk (i, j, k, p)) return val;
    val = -5e8;
    if (p == 0)
    {
        int curr = sum (i + 1, i + k) - dp (i + k, j, k, 1);
        if (curr > val) val = curr;
        if (i + j + k + 1 <= N)
        {
            curr = sum (i + 1, i + k + 1) - dp (i + k + 1, j, k + 1, 1);
            if (curr > val) val = curr;
        }
        //printf ("(%d, %d, %d, %d) -> %d\n", i, j, k, p, val);
        return val;
    }
    int curr = sum (N - j - k + 1, N - j) - dp (i, j + k, k, 0);
    if (curr > val) val = curr;
    if (i + j + k + 1 <= N)
    {
        curr = sum (N - j - k, N - j) - dp (i, j + k + 1, k + 1, 0);
        if (curr > val) val = curr;
    }
    //printf ("(%d, %d, %d, %d) -> %d\n", i, j, k, p, val);
    return val;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), s[i] = s[i - 1] + a[i];
printf ("%d\n", dp (0, 0, 1, 0));
return 0;
}