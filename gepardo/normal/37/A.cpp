#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    map <int,int> m;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        m[a]++;
    }
    int mx = 0;
    for (auto it: m) mx = max(mx, it.second);
    cout << mx << " " << m.size();
}