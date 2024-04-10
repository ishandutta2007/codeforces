#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        map<int, int> how;
        how[0] = 0;
        ll balance = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[n - i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 2)
            {
                balance--;
            }
            else
            {
                balance++;
            }
            if (!how.count(balance))
            {
                how[balance] = i + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll q = count(b.begin(), b.end(), 1) - count(b.begin(), b.end(), 2) + count(a.begin(), a.end(), 1) - count(a.begin(), a.end(), 2);
        int mini = 2 * n;
        if (how.count(q))
        {
            mini = how[q];
        }
        balance = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 2)
            {
                balance--;
            }
            else
            {
                balance++;
            }
            ll need = q - balance;
            if (how.count(need))
            {
                mini = min(mini, how[need] + (i + 1));
            }
        }
        cout << mini << "\n";
    }
    return 0;
}