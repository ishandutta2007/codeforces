#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

struct event
{
    int x, y;
    bool open;

    bool operator < (const event &o) const
    {
        return x < o.x;
    }
};

struct segtree
{
    int tsz;
    vector<int> add, mx;

    segtree (int n)
    {
        tsz = 1;
        while (tsz < n)
            tsz *= 2;

        add = mx = vector<int>(2 * tsz, 0);
    }

    void apply (int v, int x)
    {
        add[v] += x;
        mx[v] += x;
    }

    void push (int v)
    {
        for (int son = 2 * v; son <= 2 * v + 1; son++)
            apply(son, add[v]);
        add[v] = 0;
    }

    void recalc (int v)
    {
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    int getmax ()
    {
        return mx[1];
    }

    void go_add (int v, int L, int R, int l, int r, int val)
    {
        if (r <= L || R <= l)
            return;

        if (l <= L && R <= r)
        {
            apply(v, val);
            return;
        }

        push(v);

        const int M = (L + R) / 2;
        go_add(2 * v, L, M, l, r, val);
        go_add(2 * v + 1, M, R, l, r, val);
        recalc(v);
    }

    void add_seg (int l, int r, int val)
    {
        go_add(1, 0, tsz, l, r, val);
    }
};

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    vector<int> ys;
    vector<event> evs;

    int n, r;
    cin >> n >> r;
    r *= 2;

    for (int i = 0; i < n; i++)
    {
        int ox, oy;
        cin >> ox >> oy;

        int x = ox + oy;
        int y = ox - oy;

        evs.push_back(event{x, y, true});
        evs.push_back(event{x + r + 1, y, false});
        ys.push_back(y);
    }

    sort(ys.begin(), ys.end());

    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    sort(evs.begin(), evs.end());

    int ans = 0;
    segtree data(sz(ys));

    for (int i = 0; i < sz(evs); )
    {
        int j = i;
        while (j < sz(evs) && evs[j].x == evs[i].x)
            j++;

        for (int k = i; k < j; k++)
        {
            int y = evs[k].y;
            int pos_l = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            assert(ys[pos_l] == y);
            int pos_r = lower_bound(ys.begin(), ys.end(), y + r + 1) - ys.begin();

            data.add_seg(pos_l, pos_r, evs[k].open ? +1 : -1);
        }

        ans = max(ans, data.getmax());
        i = j;
    }

    cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}