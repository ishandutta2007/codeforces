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

int n, k;
vector<int> pf;
bool check(vector<int>& a, int m)
{
    int mini = 2 * n;
    pf[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pf[i + 1] = pf[i] + (a[i] < m ? -1 : 1);
        if (i + 1 >= k) mini = min(mini, pf[i + 1 - k]);
        if (pf[i + 1] - mini > 0) 
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    pf.assign(n + 1, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int lo = 1, hi = n;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (check(a, mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}