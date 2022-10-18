#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,x[100105],y[100105],w[100105];
int ans[100105];
vector<int> v[200105];
map< pii, int > mp,mpans;

int comp(int a, int b) {
    return x[a] < x[b];
}

void fail() { puts("NO"); exit(0); }

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&x[i],&y[i]);
        mp[make_pair(x[i], y[i])] = i;
        int cur = y[i] - x[i];
        v[cur + 100000].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&w[i]);
    }

    for (int i = 0; i < 200105; ++i)
        sort(v[i].begin(), v[i].end(), comp);

    for (int i = n-1; i >= 0; --i) {
        if (v[w[i] + 100000].size() == 0) fail();
        ans[i] = v[w[i] + 100000].back();
        int curx = x[v[w[i] + 100000].back()];
        int cury = y[v[w[i] + 100000].back()];
        mpans[make_pair(curx, cury)] = i + 1;
        v[w[i] + 100000].pop_back();
    }

    for (int i = 0; i < n; ++i) {
        int q = mpans[make_pair(x[i], y[i])];
        if (!q) fail();
        if (x[i] > 0) {
            int p = mpans[make_pair(x[i] - 1, y[i])];
            if (!p) fail();
            if (p >= q) fail();
        }
        if (y[i] > 0) {
            int p = mpans[make_pair(x[i], y[i] - 1)];
            if (!p) fail();
            if (p >= q) fail();
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", x[ans[i]], y[ans[i]]);

    return 0;
}