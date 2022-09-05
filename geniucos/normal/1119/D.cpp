#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
vector<long long> v(N, 0LL);
for (int i=0; i<N; i++)
    scanf ("%I64d", &v[i]);
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
vector<long long> h;
for (int i=1; i<v.size(); i++)
    h.push_back(v[i] - v[i - 1]);
sort(h.begin(), h.end());
vector<long long> sumH(h.size(), 0LL);
if (!sumH.empty())
{
    sumH[0] = h[0];
    for (int i=1; i<h.size(); i++)
        sumH[i] = sumH[i - 1] + h[i];
}
long long all = v.back() - v[0];
int M;
scanf ("%d", &M);
while (M --)
{
    long long x, y;
    scanf ("%I64d %I64d", &x, &y);
    y -= x, y ++;
    auto it = upper_bound(h.begin(), h.end(), y);
    int pos = it - h.begin(); ///h[pos..h.size()) > y
    long long spaces = all - (pos == 0 ? 0 : sumH[pos - 1]) - 1LL * y * (h.size() - pos);
    long long ans = y + all - spaces;
    printf("%I64d%c", ans, " \n"[M == 0]);
}
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/