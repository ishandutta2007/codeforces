#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

int get()
{
    int n; cin >> n; return n;
}
#define in get()

main()
{
    int n = in;
    vector <int> v;
    for (int i = 0; i < n; i++) v.push_back(in);
    sort(v.begin(), v.end());
    int tt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (tt <= v[i]) ans++; else continue;
        tt += v[i];
    }
    cout << ans;
}