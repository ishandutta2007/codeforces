#pragma comment(linker, "/STACK:1000000000")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 200 * 1000 + 10;
const int inf = 1000 * 1000 * 1000;

int n, ans_s, ans_f, col_cnt, L, R, gmv, help_size;
int ans[size];
bool flag_ex, cent_detected;
int cnum, col[size], tot[size], h[size], h_ver[size], tot_ver[size], s[size], f[size], c[size];
vector <int> vertex[size];
vector <pair <int, int> > help[size];
vector <int> max_forward[size], max_back[size];

int dfs_size(int v, int f)
{
    int s = 1;
    for (int i = 0; i < vertex[v].size(); i++)
        if (col[v] != col[vertex[v][i]])
        {
            swap(vertex[v][i], vertex[v].back());
            vertex[v].pop_back();
        }
    for (int i = 0; i < vertex[v].size(); i++)
        if (vertex[v][i] != f)
            s += dfs_size(vertex[v][i], v);
    return s;
}

int dfs_centr(int v, int f, int sz)
{
    int s = 1, d;
    bool flag = true;
    for (int i = 0; i < vertex[v].size(); i++)
        if (vertex[v][i] != f)
        {
            d = dfs_centr(vertex[v][i], v, sz);
            s += d;
            flag = flag && (d <= sz / 2);
        }
    flag = flag && (sz - s <= sz / 2);
    if (flag)
    {
        cent_detected = true;
        cnum = v;
    }
    return s;
}

int find_centroid(int v, int sz)
{
    cent_detected = false;
    cnum = -1;
    dfs_centr(v, v, sz);
    assert(cent_detected);
    return cnum;
}

void recolor(int v, int f, int c)
{
    col[v] = c;
    for (int i = 0; i < vertex[v].size(); i++)
        if (vertex[v][i] != f)
            recolor(vertex[v][i], v, c);
}

void process(int cl, int v, int tp)
{
    if (flag_ex)
        return;
    int sz = dfs_size(v, v);
    if (sz <= L)
        return;
    int ctr = find_centroid(v, sz);
    ans[ctr] = tp;
	for (int i = 0; i < vertex[ctr].size(); i++)
        recolor(vertex[ctr][i], ctr, ++col_cnt);
    for (int i = 0; i < vertex[ctr].size(); i++)
        process(col[vertex[ctr][i]], vertex[ctr][i], tp - 1);
}

int main()
{
    int mx = 0, lb, rb, mid;

    //freopen("problem_c.in", "r", stdin);
    //freopen("problem_c.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &s[i], &f[i]);
        s[i]--, f[i]--;
		vertex[s[i]].pb(f[i]);
		vertex[f[i]].pb(s[i]);
    }
	process(0, 0, 25);
	for (int i = 0; i < n; i++)
		printf("%c%c", char('A' + 25 - ans[i]), " \n"[i == n - 1]);

    return 0;
}