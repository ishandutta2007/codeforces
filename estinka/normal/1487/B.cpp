#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
#include <array>
typedef long long ll;
using namespace std;

const int inf = 1e9 + 79;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k; k--;
        if (n % 2 == 0) cout << k % n + 1 << "\n";
        else
        {
            int skip = k / (n / 2);
            cout << (k + skip) % n + 1 << "\n";
        }
    }
    return 0;
}