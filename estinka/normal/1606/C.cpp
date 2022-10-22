#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pw[11];
    pw[0] = 1;
    for (int i = 1; i < 11; i++) pw[i] = pw[i - 1] * 10;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k++;
        vector<int> a(n);
        vector<int> v;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            if (k && i)
            {
                int mx = pw[a[i] - a[i - 1]] - 1;
                v.push_back(min(k, mx));
                k -= v.back();
            }
        }
        if (k) v.push_back(k);
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
        cout << "\n";
    }
    return 0;
}