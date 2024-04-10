/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 365 (Div. 2)         |
|       Task: D                                     |
|       Date: 04. 08. 2016                          |
\--------------------------------------------------*/
// Includes
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <typename T> class fenwick
{
    private:
        vector<T> t;
        int n;
    public:
        fenwick(int nn) { init(nn); }

        void init(int nn) { n = nn; t.assign(n, 0); }

        T sum(int r)
        {
            T result = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) result ^= t[r];
            return result;
        }

        void inc(int i, T delta)
        {
            for (; i < n; i = (i | (i + 1))) t[i] ^= delta;
        }

        T sum(int l, int r) { return sum(r) ^ sum(l - 1); }
};
//End of template

inline int getInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

int n = getInt();
vector <int> v(n);
fenwick <int> f(n);
vector < vector < pair <int, int> > > r(n);
unordered_map <int, int> last;
vector <int> ans;

main()
{
    for (int i = 0; i < n; i++) v[i] = getInt();
    for (int i = 0; i < n; i++) f.inc(i, v[i]);
    int m = getInt();
    ans.resize(m);
    for (int i = 0; i < m; i++)
    {
        int a = getInt() - 1, b = getInt() - 1;
        r[b].push_back({a, i});
    }
    for (int i = 0; i < n; i++)
    {
        int q = last[v[i]] - 1;
        if (q >= 0) f.inc(q, v[q]);
        last[v[i]] = i + 1;
        f.inc(i, v[i]);

        for (int j = 0; j < r[i].size(); j++)
            ans[r[i][j].second] = f.sum(r[i][j].first, i);
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}