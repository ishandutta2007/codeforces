#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;
long long H;
pair<int, int> a[maxN];

bool ok(int K)
{
    long long space = 0;
    bool started = 0;
    for (int i=1; i<=N; i++)
        if (a[i].second <= K)
        {
            if (started) started = 0;
            else
            {
                started = 1;
                space += a[i].first;
            }
        }
    return (space <= H);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &H);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i].first), a[i].second = i, a[i].first = -a[i].first;
sort(a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    a[i].first = -a[i].first;
int p = 1, u = N, ras = 0;
while (p <= u)
{
    int mid = (p + u) >> 1;
    if (ok (mid)) ras = mid, p = mid + 1;
    else u = mid - 1;
}
printf ("%d\n", ras);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/