#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
#include <bitset>
#include <stack>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e6 + 128;
vector<string> v(maxn);
vector<vector<int> > son(maxn);
vector<int> myval(maxn, 0), p(maxn, -1);
vector<array<bool, 2> > outval(maxn);
int eval(int vr, bool son1, bool son2 = 0)
{
    if (v[vr] == "NOT") return !son1;
    if (v[vr] == "AND") return son1 & son2;
    if (v[vr] == "OR") return son1 | son2;
    if (v[vr] == "XOR") return son1 ^ son2;
}
void dfs1(int vr)
{
    for (int i : son[vr]) dfs1(i);
    if (son[vr].size()) myval[vr] = eval(vr, myval[son[vr][0]], (son[vr].size() > 1 ? myval[son[vr][1]] : 0));
}
void dfs2(int vr)
{
    if (v[vr] == "NOT")
    {
        outval[son[vr][0]][0] = outval[vr][eval(vr, 0)];
        outval[son[vr][0]][1] = outval[vr][eval(vr, 1)];
    }
    else if (v[vr] != "IN")
    {
        outval[son[vr][0]][0] = outval[vr][eval(vr, 0, myval[son[vr][1]])];
        outval[son[vr][0]][1] = outval[vr][eval(vr, 1, myval[son[vr][1]])];
        outval[son[vr][1]][0] = outval[vr][eval(vr, myval[son[vr][0]], 0)];
        outval[son[vr][1]][1] = outval[vr][eval(vr, myval[son[vr][0]], 1)];
    }
    for (int i : son[vr]) dfs2(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == "IN") cin >> myval[i];
        else
        {
            int x, y; cin >> x;
            son[i].push_back(--x);
            if (v[i] != "NOT")
            {
                cin >> y;
                son[i].push_back(--y);
            }
        }
    }
    dfs1(0);
    outval[0][0] = 0; outval[0][1] = 1;
    dfs2(0);
    for (int i = 0; i < n; i++)
    {
        if (v[i] == "IN")
        {
            cout << outval[i][myval[i] ^ 1];
        }
    }
    cout << "\n";
    return 0;
}