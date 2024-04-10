#include <iostream>
#include <vector>

using namespace std;

struct op
{
    int id;
    int a, b;
};

int n, m, q;
vector <op> ops;
vector <int> state;
vector <op> t;
vector < vector <int> > g;
int cur;

vector < vector < vector <int> > > par;
vector <int> flags;
vector <int> cnt_row;
vector <int> anses;
int ans;

void change(int was_val, int new_val, int row)
{
    if (was_val == new_val) return;
    if (new_val ^ flags[row])
        ans++, cnt_row[row]++;
    else
        ans--, cnt_row[row]--;
}

inline void do_op(op o)
{
    if (o.id == 3)
    {
        ans -= cnt_row[o.a];
        flags[o.a] = !flags[o.a];
        cnt_row[o.a] = m - cnt_row[o.a];
        ans += cnt_row[o.a];
    }
    else
    {
        int val = (o.id == 1) ? !flags[o.a] : flags[o.a];
        change(*par[o.a][o.b].rbegin(), val, o.a);
        par[o.a][o.b].push_back(val);
    }
}

inline void undo_op(op o)
{
    if (o.id == 3)
    {
        ans -= cnt_row[o.a];
        flags[o.a] = !flags[o.a];
        cnt_row[o.a] = m - cnt_row[o.a];
        ans += cnt_row[o.a];
    }
    else
    {
        int val = *par[o.a][o.b].rbegin();
        par[o.a][o.b].pop_back();
        change(val, *par[o.a][o.b].rbegin(), o.a);
    }
}

inline void init_par()
{
    par.resize(n);
    for (int i = 0; i < n; i++)
        par[i].resize(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            par[i][j].clear(),
            par[i][j].push_back(0);
    flags.resize(n);
    cnt_row.resize(n);
    for (int i = 0; i < n; i++)
        flags[i] = 0,
        cnt_row[i] = 0;
    ans = 0;
}

inline void push_op(op o)
{
    if (o.id == 4)
        cur = state[o.a+1];
    else
    {
        t.push_back(o);
        g.push_back(vector<int>());
        g[cur].push_back(t.size() - 1);
        cur = t.size() - 1;
    }
    ops.push_back(o);
    state.push_back(cur);
}

inline void init()
{
    t.resize(1);
    t[0].id = 0;
    cur = 0;
    g.clear();
    g.push_back(vector<int>());
    ops.resize(1);
    ops[0].id = 0;
    state.resize(1);
    state[0] = 0;
}

void dfs(int v)
{
    anses[v] = ans;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        do_op(t[to]);
        dfs(to);
        undo_op(t[to]);
    }
}

int main()
{
    cin >> n >> m >> q;
    init();
    for (int i = 0; i < q; i++)
    {
        op o;
        cin >> o.id >> o.a;
        if (o.id == 1 || o.id == 2)
            cin >> o.b;
        o.a--, o.b--;
        push_op(o);
    }
    anses.resize(t.size());
    init_par();
    dfs(0);
    for (int i = 1; i <= q; i++)
        cout << anses[state[i]] << endl;
    return 0;
}