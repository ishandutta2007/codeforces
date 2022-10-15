#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    map<int,int> m;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        m[a]++;
    }
    vector <int> c(n);
    for (auto it: m)
        for (int i = 0; i < it.second; i++) c[i]++;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(0, c[i] - 1);
    }
    cout << ans;
}