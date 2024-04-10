#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct triple
{
    int a, b, c;
    triple() : a(0), b(0), c(0) {}
    triple(int a, int b, int c) : a(a), b(b), c(c) {}
};

namespace std
{
    template <>
    template <typename T1, typename T2> struct hash < pair<T1, T2> >
    {
        inline size_t operator()(const pair<T1, T2>& p) const
        {
            return hash<T1>()(p.first) ^ hash<T2>()(p.second);
        }
    };
};

template <typename Comparer>
    bool gen(const vector <triple>& v, Comparer comp, int pos,
             vector < pair <char, char> >& ans, triple& val)
    {
        if (pos == v.size()) return comp(ans, val);

        ans[pos] = {'L', 'M'};
        val.a += v[pos].a;
        val.b += v[pos].b;
        if (!gen(v, comp, pos+1, ans, val)) return false;
        val.a -= v[pos].a;
        val.b -= v[pos].b;

        ans[pos] = {'L', 'W'};
        val.a += v[pos].a;
        val.c += v[pos].c;
        if (!gen(v, comp, pos+1, ans, val)) return false;
        val.a -= v[pos].a;
        val.c -= v[pos].c;

        ans[pos] = {'M', 'W'};
        val.b += v[pos].b;
        val.c += v[pos].c;
        if (!gen(v, comp, pos+1, ans, val)) return false;
        val.b -= v[pos].b;
        val.c -= v[pos].c;

        return true;
    }

template <typename Comparer>
    void launch_gen(const vector <triple>& v, Comparer comp)
    {
        vector < pair <char, char> > ans(v.size());
        triple val;
        gen(v, comp, 0, ans, val);
    }

unordered_map <pair <int, int>, pair < int, vector < pair <char, char> > > > m;
int best = -1234567890;
vector < pair <char, char> > res;

inline bool map_putter(const vector < pair <char, char> >& ans, const triple& val)
{
    pair <int, int> p(val.a - val.b, val.b - val.c);
    if (!m.count(p) || val.c > m[p].first)
        m[p] = make_pair(val.c, ans);
    return true;
}

inline bool ans_seeker(const vector < pair <char, char> >& ans, const triple& val)
{
    pair <int, int> p(val.b - val.a, val.c - val.b);
    if (m.count(p))
    {
        auto& ptr = m[p];
        if (ptr.first + val.c > best)
        {
            best = ptr.first + val.c;
            res.clear();
            res.insert(res.end(), ptr.second.begin(), ptr.second.end());
            res.insert(res.end(), ans.begin(), ans.end());
        }
    }
    return true;
}

int main()
{
    int n; cin >> n;
    vector <triple> v1, v2;
    for (int i = 0; i < n; i++)
    {
        triple t; cin >> t.a >> t.b >> t.c;
        ((i < (n / 2)) ? v1 : v2).push_back(t);
    }

    launch_gen(v1, map_putter);
    launch_gen(v2, ans_seeker);

    if (res.empty())
        cout << "Impossible" << endl;
    else
        for (auto it: res)
            cout << it.first << it.second << endl;

    return 0;
}