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
#include <queue>
#include <bitset>
#include <cmath>
#include <cassert>
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
        int n;
        cin >> n;
        int x = 1;
        while ((x << 1) < n) x <<= 1;
        vector<int> p(n);
        for (int i = 0; i < n; i++)p[i] = i;
        reverse(p.begin(), p.begin() + x);
        for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
    }
    return 0;
}