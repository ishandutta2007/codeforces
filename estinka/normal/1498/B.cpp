#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        vector<int>w(n);
        for (int i = 0; i < n; i++) cin >> w[i];
        sort(w.begin(), w.end(), greater<int>());
        multiset<int> v;
        for (int i = 0; i < n; i++)
        {
            auto place = v.lower_bound(w[i]);
            if (place == v.end()) v.insert(W - w[i]);
            else
            {
                ll val = *place - w[i];
                v.erase(place);
                v.insert(val);
            }
        }
        cout << v.size() << "\n";
    }
    return 0;
}