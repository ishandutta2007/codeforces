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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        set<int, greater<int>>s;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            s.insert(i + 1);
        }
        vector<int> nw;
        while (!s.empty())
        {
            int w = *s.begin();
            vector<int> tmp;
            while (tmp.empty() || tmp.back() != w)
            {
                tmp.push_back(p.back());
                s.erase(tmp.back());
                p.pop_back();
            }
            for (int i = tmp.size() - 1; i >= 0; i--) nw.push_back(tmp[i]);
        }
        for (int i = 0; i < nw.size(); i++) cout << nw[i] << " ";
        cout << "\n";
    }
    return 0;
}