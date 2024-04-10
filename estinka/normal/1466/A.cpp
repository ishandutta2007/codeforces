#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        // zakladna * vyska / 2. Musia mat roznu zakladnu. O(n^2 log n) si mozeme dovolit
        int n;
        cin >> n;
        vector<int> x(n);
        bitset<200> b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            for (int j = 0; j < i; j++)
            {
                b[abs(x[i] - x[j])] = 1;
            }
        }
        cout << b.count() << "\n";
    }
    return 0;
}