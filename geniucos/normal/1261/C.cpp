#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, M;
char currS[maxN];
string c[maxN];
vector<vector<int>> s, s2;

int getSum(int a1, int b1, int a2, int b2, vector<vector<int>> &s)
{
    return s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1];
}

bool possible(int i, int j, int T)
{
    int a1 = i - T, b1 = j - T, a2 = i + T, b2 = j + T;
    if (a1 < 1 || b1 < 1 || a2 > N || b2 > M) return 0;
    return (getSum(a1, b1, a2, b2, s) == (a2 - a1 + 1) * (b2 - b1 + 1));
}

bool ok (int T)
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        {
            int curr = possible(i, j, T);
            s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1] + curr;
        }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (c[i][j - 1] == 'X')
            {
                int a1 = max(1, i - T), a2 = min(N, i + T), b1 = max(1, j - T), b2 = min(M, j + T);
                if (getSum(a1, b1, a2, b2, s2) == 0)
                    return 0;
            }
            else
            {
                int a1 = max(1, i - T), a2 = min(N, i + T), b1 = max(1, j - T), b2 = min(M, j + T);
                assert(getSum(a1, b1, a2, b2, s2) == 0);
            }
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
s = s2 = vector<vector<int>> (N + 1, vector<int> (M + 1, 0));
for (int i=1; i<=N; i++)
{
    scanf ("%s\n", currS), c[i] = currS;
    for (int j=1; j<=M; j++)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (currS[j - 1] == 'X');
}
int p = 0, u = min(N, M), mid, ras = 0;
while (p <= u)
{
    mid = (p + u) >> 1;
    if (ok (mid)) ras = mid, p = mid + 1;
    else u = mid - 1;
}
printf ("%d\n", ras);
for (int i=1; i<=N; i++, printf("\n"))
    for (int j=1; j<=M; j++)
        if (possible(i, j, ras)) printf ("X");
        else printf(".");
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/