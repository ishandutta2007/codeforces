#include<bits/stdc++.h>

using namespace std;

const int maxN = 2020;
int N, K;
char s[maxN], t[maxN];
vector<pair<int, int>> ans;

void performMove(int i, int j)
{
    reverse(s + i, s + j + 1);
    ans.push_back({i, j});
}

void print()
{
    printf("%d\n", ans.size());
    for (auto p : ans)
        printf ("%d %d\n", p.first, p.second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d\n", &N, &K);
    scanf ("%s", s + 1);
    for (int i=1; i<K; i++)
        t[2 * i - 1] = '(',
        t[2 * i] = ')';
    for (int j=1; j<=N / 2 - (K - 1); j++)
        t[2 * K - 2 + j] = '(';
    for (int j=2 * K + N / 2 - (K - 1) - 1; j<=N; j++)
        t[j] = ')';
    t[N + 1] = 0;
    //printf("%s\n", t + 1);
    for (int i=1; i<=N; i++)
        if (t[i] != s[i])
        {
            int j = i;
            while (s[j] != t[i])
                j ++;
            performMove(i, j);
        }
    print();
    for (int i=1; i<=N; i++)
        assert(s[i] == t[i]);
    ans.clear();
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/