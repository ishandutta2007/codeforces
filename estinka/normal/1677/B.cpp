#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
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
        int n, m;
        cin >> n >> m;
        vector<int> sumc(n * m, 0), sumr(n * m, 0);
        vector<int> v(n * m);
        for (int i = 0; i < n * m; i++)
        {
            char c;
            cin >> c;
            v[i] = (c == '1' ? 1 : 0);
        }
        // stlpce
        vector<int> f(m, 0);
        int bad = m;
        for (int i = 0; i < n * m; i++)
        {
            f[i % m] += v[i];
            if (v[i] == 1 && f[i % m] == 1) bad--;
            sumc[i] = m - bad;
        }
        // riadky - najprv spocitame tie zle
        int cnt0 = 0;
        for (int i = 0; i < n * m; i++)
        {
            if (i >= m) sumr[i] += sumr[i - m];
            if (v[i] == 1) cnt0 = 0;
            if (v[i] == 0)
            {
                cnt0++;
                if (cnt0 >= m) sumr[i]++;
            }
        }
        for (int i = 0; i + 1 < m; i++)
        {
            if (v[i] == 1) break;
            for (int j = i; j < n * m; j += m) sumr[j]++; // posledny riadok je zly
        }
        for (int i = 0; i < n * m; i++)
        {
            int all = i / m + 1;
            sumr[i] = all - sumr[i]; // vsetky - zle
        }
        // vypis
        for (int i = 0; i < n * m; i++)
        {
            cout << sumc[i] + sumr[i] << " \n"[i == n * m - 1];
        }
    }
    return 0;
}