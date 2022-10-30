#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>

#include <ctime>
#include <queue>
#include <unordered_map>
#include <set>
#include <cassert>

using namespace std;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

int up (int n)
{
    int r = 1;

    while (r < n)
        r <<= 1;

    return r;
}

class segtree
{
    vector<int> arr;

    int sum (int l, int r, int cl, int cr, int v)
    {
        if (r <= cl || cr <= l)
            return 0;
        if (l <= cl && cr <= r)
            return arr[v];

        auto ct = (cl + cr) / 2;

        return sum (l, r, cl, ct, 2 * v) +
            sum (l, r, ct, cr, 2 * v + 1);
    }

public:
    segtree (int n) : arr (2 * up (n))
    {}

    void add (int wh, int x)
    {
        wh += arr.size () / 2;

        while (wh > 0)
        {
            arr[wh] += x;
            wh >>= 1;
        }
    }

    int sum (int l, int r)
    {
        return sum (l, r, 0, arr.size () / 2, 1);
    }

    int sum (int l = 0)
    {
        return sum (l, arr.size () / 2, 0, arr.size () / 2, 1);
    }
};

template<class T>
int sign (T x)
{
    return x > 0 ? 1 : x == 0 ? 0 : -1;
}

long long cmp (const pair<int, int> &a, const pair<int, int> &b, int w)
{
    return sign ((long long)(b.second + w) * (long long)(a.second + w)) *
        (a.first * (long long)(b.second + w) - b.first * (long long)(a.second + w));
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, w;

    cin >> n >> w;

    vector<pair<int, int>> arr (n);

    for (auto &it : arr)
        cin >> it.first >> it.second;

    sort (arr.begin (), arr.end (), [w](const pair<int, int> &a, const pair<int, int> &b) {
        return cmp (a, b, -w) < 0;
    });
    stable_sort (arr.begin (), arr.end (), [w](const pair<int, int> &a, const pair<int, int> &b) {
        return cmp (a, b, w) < 0;
    });

    vector<pair<pair<int, int>, int>> ord (n);

    for (int i = 0; i < ord.size (); i++)
        ord[i] = {arr[i], i};

    stable_sort (ord.begin (), ord.end (), [w](const pair<pair<int, int>, int> &a,
                                               const pair<pair<int, int>, int> &b) {
        return cmp (a.first, b.first, -w) < 0;
    });

    long long inv = 0;

    segtree st (ord.size ());

    for (const auto &it : ord)
    {
        inv += st.sum (it.second);
        st.add (it.second, 1);
    }

    for (int l = 0, r; l < arr.size (); l = r)
    {
        for (r = l + 1; r < arr.size () && cmp (arr[l], arr[r], w) == 0; r++);

        inv += (r - l) * (long long)(r - l - 1) / 2;
    }

    if (w != 0)
    {
        for (int l = 0, r; l < arr.size (); l = r)
        {
            for (r = l + 1; r < arr.size () && cmp (ord[l].first, ord[r].first, -w) == 0; r++);

            inv += (r - l) * (long long)(r - l - 1) / 2;
        }
    }

    cout << inv << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif

    return 0;
}