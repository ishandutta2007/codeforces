#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mini = max(0, n - 2);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = 2;
                for (int k = 0; k < n; k++) if (k != i && k != j)
                {
                    int num = (a[j] - a[i]) * (k - i);
                    if (num % (j - i) != 0) continue;
                    if (a[k] == a[i] + num / (j - i)) cnt++;
                }
                mini = min(mini, n - cnt);
            }
        }
        //cout << "               ";
        cout << mini << "\n";
    }
    return 0;
}