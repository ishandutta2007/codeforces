#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
#define pii pair<int,int>
using namespace std;

int n,a[100105];

pii dfs(int v, int lvl) { /// cnt_added/mx_path
    if (lvl == n) return make_pair(0,0);
    pii qqq1 = dfs(v+v, lvl+1);
    pii qqq2 = dfs(v+v+1, lvl+1);
    int mx_path = max(qqq1.second + a[v+v], qqq2.second + a[v+v+1]);
    int cnt_added = max(qqq1.second + a[v+v], qqq2.second + a[v+v+1]) -
                    min(qqq1.second + a[v+v], qqq2.second + a[v+v+1])
                    + qqq1.first + qqq2.first;
    return make_pair(cnt_added, mx_path);
}

int main()
{
    cin >> n;
    for (int i = 2; i <= (2 << n) - 1; ++i) {
        cin >> a[i];
    }
    cout << dfs(1, 0).first;

    return 0;
}