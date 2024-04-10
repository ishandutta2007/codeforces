#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int inf = 123456789;

int getInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

vector<int> getVectorInt(int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(getInt());
    return v;
}

map<int,int> compressor;
vector<int> numUpper, numLower;

void addToCompressor(int n)
{
    compressor[n]++;
}

void compressIt()
{
    int cnt = 0;
    for (map<int,int> :: iterator it = compressor.begin(); it != compressor.end(); it++)
    {
        int s = it -> second;
        it -> second = cnt;
        for (int i = 0; i < s; i++)
        {
            numUpper.push_back(cnt + s - 1);
            numLower.push_back(cnt);
        }
        cnt += s;
    }
}

int numberCompress(int n)
{
    return compressor[n]++;
}

typedef pair<int,int> pii;
const pii minT = {0, -inf};
const int segtreePow = 20;
const int segtreeMax = 1 << segtreePow;
const int segtreeLen = segtreeMax * 2;

template <typename T>
    class segtree
    {
        public:
        vector<T> tree;
        void clear()
        {
            for (int i = 0; i < segtreeLen; i++) tree[i] = minT;
        }
        segtree() : tree(segtreeLen)
        {
            clear();
        }
        void update(int i, int tl, int tr, int v, T val)
        {
            if (tl == tr) tree[i] = val;
                else
                {
                    int tm = (tl + tr) / 2;
                    if (v <= tm) update(i * 2, tl, tm, v, val);
                        else update(i * 2 + 1, tm + 1, tr, v, val);
                    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
                }
        }
        void update(int v, T val)
        {
            update(1, 0, segtreeMax - 1, v, val);
        }
        T query(int i, int tl, int tr, int l, int r)
        {
            if (l > r) return minT;
            if (l == tl && r == tr) return tree[i];
            int tm = (tl + tr) / 2;
            return max(query(i * 2, tl, tm, l, min(tm, r)),
                       query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
        T query(int l, int r)
        {
            return query(1, 0, segtreeMax - 1, l, r);
        }
    };

int main()
{
    int n = getInt(), m = getInt();
    vector<int> v = getVectorInt(n);
    vector< pair<pii,int> > q;
    for (int i = 0; i < m; i++) q.push_back({{getInt() - 1, getInt()}, i});
    for (int i = 0; i < n; i++) addToCompressor(v[i]);
    for (int i = 0; i < m; i++) addToCompressor(q[i].first.second);
    compressIt();
    for (int i = 0; i < n; i++) v[i] = numberCompress(v[i]);
    for (int i = 0; i < m; i++) q[i].first.second = numberCompress(q[i].first.second);
    vector<int> sl(n), sr(n), sw(n);
    segtree<pii> t;
    for (int i = 0; i < n; i++)
    {
        sl[i] = t.query(0, numLower[v[i]] - 1).first + 1;
        t.update(v[i], {sl[i], i});
    }
    t.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        sr[i] = t.query(numUpper[v[i]] + 1, segtreeMax - 1).first + 1;
        t.update(v[i], {sr[i], i});
    }
    int maxLen = t.query(0, segtreeMax - 1).first;
    int rRange = t.query(0, segtreeMax - 1).second;
    for (int i = 0; i < n; i++)
    {
        if (i >= rRange) sw[i] = maxLen - 1; else sw[i] = maxLen;
        t.update(v[i], minT);
        pii qLen = t.query(numUpper[v[i]] + 1, segtreeMax - 1);
        if (qLen.first == 0) qLen.second = n;
        if (qLen.first + sl[i] == maxLen) rRange = max(rRange, qLen.second);
    }
    segtree<pii> l, r;
    int curI = 0;
    for (int i = 1; i < n; i++) r.update(v[i], {sr[i], i});
    sort(q.begin(), q.end());
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        int f = q[i].first.first, s = q[i].first.second;
        while (curI < f)
        {
            l.update(v[curI], {sl[curI], curI});
            curI++;
            r.update(v[curI], minT);
        }
        int res = max(sw[f],
                      l.query(0, numLower[s] - 1).first +
                      r.query(numUpper[s] + 1, segtreeMax - 1).first + 1);
        ans[q[i].second] = res;
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}