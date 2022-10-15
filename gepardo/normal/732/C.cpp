#include <iostream>

using namespace std;

#define int long long

main()
{
    int a[3]; cin >> a[0] >> a[1] >> a[2];
    if (a[0] < 2 && a[1] < 2 && a[2] < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 3 * max(a[0], max(a[1], a[2])) - a[0] - a[1] - a[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            ans = min(ans, 3 * max(a[0], max(a[1], a[2])) - a[0] - a[1] - a[2]);
            a[j]++;
        }
        for (int j = 0; j < 3; j++) a[j]--;
        a[i]++;
    }
    for (int i = 0; i < 3; i++) a[i]--;
    cout << ans << endl;
}