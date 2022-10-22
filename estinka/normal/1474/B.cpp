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
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> p;
    for (int i = 2; i < 20079; i++)
    {
        bool pr = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                pr = false;
                break;
            }
        if (pr) p.push_back(i);
    }
    while (t--)
    {
        int d;
        cin >> d;
        int pr1 = *lower_bound(p.begin(), p.end(), d + 1);
        int pr2 = *lower_bound(p.begin(), p.end(), pr1 + d);
        cout << pr1 * pr2 << "\n";
    }
    return 0;
}