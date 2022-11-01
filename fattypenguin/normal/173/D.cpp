#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

VI det[2];
VI e[100007];
VI col, bel, ans;

void bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        det[col[now]].PB(now);
        TR(it, e[now])
        {
            assert(col[now] != col[*it]);
            if (1-col[now] == col[*it])
                continue;
            assert(col[*it] == -1);
            col[*it] = 1 - col[now];
            Q.push(*it);
        }
    }
}

void color(int idx)
{
    int cnt = 3;
    TR(it, det[0])
    {
        if (ans[*it] != -1) continue;
        if (!cnt) ++idx, cnt = 3;
        ans[*it] = idx;
        --cnt;
    }
    assert(!cnt || 3 == cnt);
    TR(it, det[1])
    {
        if (ans[*it] != -1) continue;
        if (!cnt) ++idx, cnt = 3;
        ans[*it] = idx;
        --cnt;
    }
}

int main()
{
    int n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    k = n / 3;
    REP(i, m)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        e[x].PB(y);
        e[y].PB(x);
    }
    col.resize(n);
    fill(ALL(col), -1);
    VI lr[3];
    REP(i, n) if (-1 == col[i])
    {
        col[i] = 0;
        bfs(i);
    }
/*
    cout << "left part: \n";
    TR(it, det[0]) cout << *it << " ";
    cout << endl;
*/

    bool noans = false;
    ans.resize(n);
    fill(ALL(ans), -1);
    if (det[0].size()%3 == 0)
        color(1);
    else
    {
        int left = 0;
        if (det[1].size()%3 == 1)
            left = 1;
        bool ok = false;
        TR(it, det[left])
            if ((int)e[*it].size() <= (int)det[1-left].size() - 2)
            {
                ok = true;
                vector<bool> cant;
                cant.resize(n);
                fill(ALL(cant), false);
                TR(it1, e[*it])
                    cant[*it1] = true;
                int colored = 0;
                TR(it1, det[1-left])
                {
                    if (colored == 2) break;
                    if (!cant[*it1])
                    {
                        ans[*it1] = 1;
                        ++colored;
                    }
                }
                ans[*it] = 1;
                break;
            }
        if (ok)
        {
            color(2);
            goto there;
        }
        int t1 = -1, t2 = -1;
        int right = 1 - left;
        TR(it, det[right])
        {
            if ((int)e[*it].size() <= (int)det[left].size()-2)
            {
          //      cout << "e[*it].size() = " << e[*it].size() << " (int)det[left].size()-2 = " << (int)det[left].size()-2 << endl;
                if (t1 == -1)
                {
                    t1 = *it;
                    continue;
                }
                t2 = *it;
                break;
            }
        }
        if (t2 == -1)
        {
            noans = true;
            goto there;
        }

    //    cout << "t1 = " << t1 << " t2 = " << t2 << endl;

        vector<bool> cant;
        cant.resize(n);
        fill(ALL(cant), false);
        TR(it1, e[t1])
            cant[*it1] = true;
        int colored = 0;
        ans[t1] = 1;
        TR(it1, det[left])
        {
            if (colored == 2) break;
            if (!cant[*it1])
            {
                ans[*it1] = 1;
                ++colored;
            }
        }

        fill(ALL(cant), false);
        TR(it1, e[t2])
            cant[*it1] = true;colored = 0;
        ans[t2] = 2;
        TR(it1, det[left])
        {
            if (colored == 2) break;
            if (!cant[*it1])
            {
                ans[*it1] = 2;
                ++colored;
            }
        }

        color(3);
    }
there:
    if (noans)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    REP(i, n)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}