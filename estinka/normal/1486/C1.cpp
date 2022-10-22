#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <array>
typedef long long ll;
typedef long double ld;
using namespace std;

int ask(int l, int r)
{
    if (l == r) return -1;
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    int m2 = ask(0, n - 1);
    int m2pref = ask(0, m2);
    int ans = -1;
    if (m2 > 0 && m2pref == m2) // maximum lies somewhere on the prefix
    {
        int lo = 0, hi = m2 - 1;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (ask(mid, m2) == m2) lo = mid; 
            else hi = mid - 1;
        }
        ans = lo;
    }
    else // we have to find the first good position 
    {
        int lo = m2 + 1, hi = n - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (ask(m2, mid) == m2) hi = mid; // this position is good but maybe we can go even lower
            else lo = mid + 1;
        }
        ans = lo;
    }
    cout << "! " << ans + 1 << endl;
    return 0;
}