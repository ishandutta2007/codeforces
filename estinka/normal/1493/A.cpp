#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
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
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            if (i != k && i * 2 >= k) v.push_back(i);
        }
        cout << v.size() << "\n";
        for (int i : v) cout << i << " ";
        cout << "\n";
    }
    return 0;
}