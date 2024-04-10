#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

main()
{
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    /*
    for (int i = 0; i < n; i++)
        cout << a[i] << " " << b[i] << endl;
    */
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
        ans = ans % 10007;
    }
    cout << ans;
    return 0;
}