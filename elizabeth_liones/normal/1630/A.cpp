#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>
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
        int n, k;
        cin >> n >> k;
        if (n == 4 && k == 3)
        {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int> > ans;
        if (k == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                 ans.push_back({ i, n - 1 - i });
            }
        }
        else if (k != n - 1)
        {
            ans.push_back({ k, n - 1 });
            ans.push_back({ 0, n - 1 - k });
            for (int i = 0; i < n / 2; i++)
            {
                if (i != 0 && i != n - 1 - k && i != k)
                {
                    ans.push_back({ i, n - 1 - i });
                }
            }
        }
        else
        {
            ans.push_back({ 0, n - 4 });
            ans.push_back({ 1, 3 });
            ans.push_back({ 2, n - 3 });
            ans.push_back({ n - 2, n - 1 });
            for (int i = 4; i < n / 2; i++)
            {
                ans.push_back({ i, n - 1 - i });
            }
        }
        //cout << "\n";
        int sum = 0;
        for (pair<int, int> i : ans)
        {
            cout << i.first << " " << i.second << "\n";
            sum += i.first & i.second;
        }
        //cout << sum << "\n";
        //cout << "\n";
    }
    return 0;
}