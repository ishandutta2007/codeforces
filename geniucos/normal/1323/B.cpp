#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;

void read (int length, vector < int > &input)
{
    input.resize (length);
    for (int i=0; i<length; i++)
        scanf ("%d", &input[i]);
}

vector < int > solve (vector < int > &a)
{
    vector < int > ans (a.size () + 1, 0);
    for (int i=0; i<a.size (); i++)
        if (a[i])
        {
            int j = i;
            while (j + 1 < a.size () && a[j + 1] == 1)
                j ++;
            ans[j - i + 1] ++;
            i = j;
        }
    long long sumCntL = 0, sumCnt = 0;
    for (int i=a.size (); i>=1; i--)
        sumCnt += ans[i], sumCntL += 1LL * ans[i] * i,
        ans[i] = sumCntL - 1LL * (i - 1) * sumCnt;
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, M;
long long K;
scanf ("%d %d %I64d", &N, &M, &K);
vector < int > a, b;
read (N, a);
read (M, b);
vector < int > lin = solve (a), col = solve (b);
long long ans = 0;
for (int i=1; i<=N; i++)
    if (K % i == 0 && K / i <= M)
        ans += 1LL * lin[i] * col[K / i];
printf ("%I64d\n", ans);
return 0;
}