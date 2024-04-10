#include<bits/stdc++.h>

using namespace std;

const int maxN = 109;
int N, t[maxN];
char s[maxN][maxN][maxN];

void buildTenativeT(int adj1) {
    ///suppose 1 and adj1 are adjacent, then build t
    for (int i=1; i<=N; i++)
        t[i] = -1;
    t[1] = 0;
    function<void(int, int)> dfs = [&](int nod, int otherNeighbour) {
        for (int it = 1; it <= N; it ++)
            if (t[it] == -1 && (it == otherNeighbour || s[otherNeighbour][it][nod] == '1'))
                t[it] = nod, dfs(it, nod);
    };
    dfs(1, adj1);
}

int d[maxN][maxN];
vector<int> v[maxN];
bool check() {
    for (int i=1; i<=N; i++) {
        v[i].clear ();
        if (t[i] == -1)
            return 0;
    }
    for (int i=2; i<=N; i++)
        v[i].push_back(t[i]), v[t[i]].push_back(i);
    function<void(int, int, int[])> dfsDist = [&](int nod, int fath, int d[]) {
    //auto dfsDist = [&](int nod, int fath, int d[]) {
        for (auto it : v[nod])
            if (it != fath)
                d[it] = d[nod] + 1,
                dfsDist(it, nod, d);
    };
    for (int i=1; i<=N; i++)
        dfsDist(i, -1, d[i]);
    for (int i=1; i<N; i++)
        for (int j=i + 1; j<=N; j++)
            for (int k=1; k<=N; k++)
                if (s[i][j][k] - '0' != (d[i][k] == d[j][k]))
                    return 0;
    return 1;
}

void solve() {
    for (int i=2; i<=N; i++) {
        buildTenativeT(i);
        if (!check())
            continue;
        printf("Yes\n");
        for (int i=2; i<=N; i++)
            printf("%d %d\n", t[i], i);
        return ;
    }
    printf("No\n");
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d\n", &N);
    for (int i=1; i<N; i++)
        for (int j=i + 1; j<=N; j++) {
            scanf("%s", s[i][j] + 1), assert(strlen(s[i][j] + 1) == N);
            for (int k=1; k<=N; k++)
                s[j][i][k] = s[i][j][k];
        }
    solve();
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/