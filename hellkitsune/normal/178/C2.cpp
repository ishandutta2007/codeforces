#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

const int inf = (int)1e9 + 7;
const int mx = (int)2e5;
long long ans = 0;
map<int, long long> idmap;
int hash[mx], h, n, m, id, hh;
vector<int> gtree[mx];
int gnum[mx], ind[mx], cnt[mx] = {0}, gcount = 0, treeR[mx];
string s;

void branch_init(int pos, int l, int r, int t)
{
    if (l >= cnt[t])
    {
        if (l < r)
            gtree[t][pos] = inf;
        return;
    }
    gtree[t][pos] = l;
    if (l < r)
    {
        branch_init(pos * 2 + 1, l, (l + r) / 2, t);
        branch_init(pos * 2 + 2, (l + r) / 2 + 1, r, t);
    }
}

void tree_init(int t)
{
    for (treeR[t] = 1; treeR[t] < cnt[t]; treeR[t] *= 2)
        ;
    --treeR[t];
    gtree[t].resize(treeR[t] + cnt[t]);
    branch_init(0, 0, treeR[t], t);
}

int gtree_min(int pos, int l, int r, int L, int R, int t)
{
    if (l > r)
        return inf;
    if ((l == L) && (r == R))
        return gtree[t][pos];
    return min(gtree_min(pos * 2 + 1, l, min(r, (L + R) / 2), L, (L + R) / 2, t),
               gtree_min(pos * 2 + 2, max((L + R) / 2 + 1, l), r, (L + R) / 2 + 1, R, t));
}

int tree_min(int l, int r, int t)
{
    return gtree_min(0, l, r, 0, treeR[t], t);
}

void tree_modify(int k, int val, int t)
{
    int pos = treeR[t] + k;
    gtree[t][pos] = val;
    if (pos)
    {
        pos = (pos - 1) / 2;
        if (pos * 2 + 2 >= treeR[t] + cnt[t])
            gtree[t][pos] = gtree[t][pos * 2 + 1];
        else
            gtree[t][pos] = min(gtree[t][pos * 2 + 1], gtree[t][pos * 2 + 2]);
    }
    while (pos)
    {
        pos = (pos - 1) / 2;
        gtree[t][pos] = min(gtree[t][pos * 2 + 1], gtree[t][pos * 2 + 2]);
    }
}

int main(void)
{
    cin >> h >> m >> n;
    memset(gnum, -1, sizeof(int) * h);
    int j;
    for (int i = 0; i < h; ++i)
        if (gnum[i] == -1)
        {
            for (j = i; gnum[j] == -1; j = (j + m) % h)
            {
                gnum[j] = gcount;
                ind[j] = cnt[gcount]++;
            }
            ++gcount;
        }
    for (int i = 0; i < gcount; ++i)
        tree_init(i);
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> id;
        if (s == "+")
        {
            cin >> hh;
            int hpos = tree_min(ind[hh], cnt[gnum[hh]] - 1, gnum[hh]);
            if (hpos == inf)
                hpos = tree_min(0, ind[hh] - 1, gnum[hh]);
            if (hpos >= ind[hh])
                ans += hpos - ind[hh];
            else
                ans += cnt[gnum[hh]] - ind[hh] + hpos;
            tree_modify(hpos, inf, gnum[hh]);
            idmap[id] = gnum[hh] * 1ll * inf + hpos;
        }
        else
        {
            long long pos = idmap[id];
            tree_modify(pos % inf, pos % inf, pos / inf);
        }
    }
    cout << ans << endl;
    return 0;
}