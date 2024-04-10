#include<bits/stdc++.h>

using namespace std;

int N, M;

void tryValue(int x, vector<int>& ans) {
    if (N % x == 0 || (N - 1) % x == 0 || (N - 2) % x == 0)
        ans.push_back(x);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    int K = N + M - 2;
    vector<int> v[2];
    for (int i=1; 1LL * i * i <= K; i++) {
        if (K % i == 0) {
            tryValue(i, v[0]);
            if (i < K / i)
                tryValue(K / i, v[1]);
        }
        else
        if (i == 2)
            v[0].push_back(i);
    }
    printf("%d", v[0].size() + v[1].size());
    for (auto it : v[0])
        printf(" %d", it);
    reverse(v[1].begin(), v[1].end());
    for (auto it : v[1])
        printf(" %d", it);
    printf("\n");
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/