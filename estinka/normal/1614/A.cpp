#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (l <= x && x <= r) a.push_back(x);
        }
        sort(a.begin(), a.end());
        int sum = 0, cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (sum + a[i] <= k)
            {
                sum += a[i];
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}