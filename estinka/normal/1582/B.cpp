#include <iostream>
#include <vector>
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
        int n;
        cin >> n;
        vector<int> a(n);
        ll ans = 1, one = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1) one++;
            if (a[i] == 0) ans <<= 1ll;
        }
        cout << ans * one << "\n";
    }
    return 0; 
}