#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, a[maxN], b[maxN];
vector<int> ans, ids[2];

bool cmp1(int i, int j) {return b[i] > b[j];}
bool cmp2(int i, int j) {return b[i] < b[j];}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]), ids[a[i] > b[i]].push_back(i);
sort(ids[0].begin(), ids[0].end(), cmp1);
if (!ids[0].empty())
{
    vector<int> curr;
    int last = b[ids[0][0]];
    for (auto j : ids[0])
        if (a[j] < last)
            curr.push_back(j), last = b[j];
    ans = curr;
}
sort(ids[1].begin(), ids[1].end(), cmp2);
if (!ids[1].empty())
{
    vector<int> curr;
    int last = b[ids[1][0]];
    for (auto j : ids[1])
        if (a[j] > last)
            curr.push_back(j), last = b[j];
    if (curr.size() > ans.size())
        ans = curr;
}
printf("%d\n", ans.size());
for (auto p : ans)
    printf("%d ", p);
printf("\n");
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/