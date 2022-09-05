#include<bits/stdc++.h>

using namespace std;

int N, M, ans[300009], b[300009];
long long T;
pair < pair < int, int >, int > a[300009];

int main ()
{
scanf ("%d %d %I64d", &N, &M, &T);
long long rot = 0;
for (int i=0; i<N; i++)
{
    char c;
    scanf ("%d %c", &a[i].first.first, &c), a[i].second = i, a[i].first.first --;
    if (c == 'L') a[i].first.second = -1;
    else a[i].first.second = +1;
    int finPos = ((long long) a[i].first.first + 1LL * a[i].first.second * T) % M;
    if (finPos < 0) finPos += M;
    b[i] = finPos;
    if (a[i].first.second == -1)
    {
        long long times = T - a[i].first.first - 1;
        if (times >= 0)
        {
            times /= M, times ++;
            rot = (rot - times) % N;
        }
    }
    else
    {
        long long times = T - (M - 1 - a[i].first.first) - 1;
        if (times >= 0)
        {
            times /= M, times ++;
            rot = (rot + times) % N;
        }
    }
}
if (rot < 0) rot += N;
rot = (N - rot) % N;
sort (a, a + N);
sort (b, b + N);
for (int i=0; i<N; i++)
    ans[a[(i + rot) % N].second] = b[i];
for (int i=0; i<N; i++)
    printf ("%d%c", ans[i] + 1, " \n"[i == N - 1]);
return 0;
}