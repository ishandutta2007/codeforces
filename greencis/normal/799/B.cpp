#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

priority_queue< int, vector<int>, greater<int> > q[3][3];
int n, m, x, p[200105], a[200105], b[200105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --a[i]; --b[i];
        q[a[i]][b[i]].push(p[i]);
    }
    cin >> m;
    while (m--) {
        cin >> x;
        --x;
        int mn = 2e9, mni = -1, mnj = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (q[i][j].empty())
                    continue;
                if (i != x && j != x)
                    continue;
                if (q[i][j].top() < mn)
                    mn = q[i][j].top(), mni = i, mnj = j;
            }
        }
        if (mni != -1) {
            cout << mn << " ";
            q[mni][mnj].pop();
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}