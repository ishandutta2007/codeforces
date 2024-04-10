#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

int n, m;
vector <int> v;

bool yes(int time)
{
    int sc = 0, curSt = 0;
    vector <int> q = v;
    for (int i = n - 1; i >= 0; i--)
        while (q[i] != 0)
        {
            if (time - i <= 0) return false;
            if (curSt == 0)
            {
                sc++;
                if (sc > m) return false;
                curSt = time - i;
            }
            if (curSt < q[i]) q[i] -= curSt, curSt = 0;
                else curSt -= q[i], q[i] = 0;
        }
    return true;
}

int binSearch(int l, int r)
{
    if (l == r) return l;
    int m = (l + r) / 2;
    if (yes(m)) return binSearch(l, m);
        else return binSearch(m + 1, r);
}

signed main()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << binSearch(0, 2e18) + 1;
}