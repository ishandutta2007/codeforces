#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, p[maxN], pos[maxN];
vector<pair<int, int>> ans;

int mod(int x)
{
    if (x < 0) return -x;
    return x;
}

int mod(int x, int y) {return mod(x - y);}

void doMove(int i, int j)
{
    assert(mod(i, j) >= N / 2);
    ans.push_back({i, j});
    swap(p[i], p[j]);
    swap(pos[p[i]], pos[p[j]]);
}

void print()
{
    for (int i=1; i<=N; i++)
        assert(p[i] == i);
    printf("%d\n", ans.size());
    for (auto p : ans)
        printf("%d %d\n", p.first, p.second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]), pos[p[i]] = i;
int K = N / 2;
for (int i=2; i<N; i++)
if (p[i] != i)
{
    int q = pos[i];
    if (mod(i, q) >= K)
    {
        doMove(i, q);
        continue;
    }
    int r = 1;
    if (mod(i, r) < K || mod(q, r) < K)
        r = N;
    if (mod(i, r) >= K && mod(q, r) >= K)
    {
        doMove(q, r);
        doMove(i, r);
        continue;
    }
    if (i < q)
    {
        ///1  i  q  n
        doMove(q, 1);
        doMove(1, N);
        doMove(N, i);
    }
    else
    {
        doMove(q, N);
        doMove(1, N);
        doMove(1, i);
    }
}
if(p[1] != 1)
    doMove(1, N);
print();
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/