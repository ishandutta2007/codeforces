#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,u[80005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < 80005; ++i) u[i] = 2e9;
    queue< pii > q;
    q.push(make_pair(0, n));
    while (!q.empty()) {
        int curp = q.front().first;
        int curnum = q.front().second;
        q.pop();
        if (curnum <= 0 || curnum >= 80005) continue;
        if (u[curnum] <= curp) continue;
        u[curnum] = curp;
        ++curp;
        q.push(make_pair(curp, curnum * 2));
        q.push(make_pair(curp, curnum - 1));
    }
    cout << u[m];

    return 0;
}