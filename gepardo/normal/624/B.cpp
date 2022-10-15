#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long res = v[0];
    int beg = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] >= beg) beg = min(beg - 1, v[i] - 1); else beg = v[i];
        if (beg >= 0) res += beg;
    }
    cout << res;
}