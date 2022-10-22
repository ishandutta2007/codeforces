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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n % 2 == 1)
        {
            for (int i = 0; i < 3; i++) if (a[i] + a[(i + 1) % 3] != 0)
            {
                b[i]           = -a[(i + 2) % 3];
                b[(i + 1) % 3] = -a[(i + 2) % 3];
                b[(i + 2) % 3] = a[i] + a[(i + 1) % 3];
                break;
            }
        }
        for (int i = (n % 2 == 1) ? 3 : 0; i < n; i += 2)
        {
            b[i]     = -a[i + 1];
            b[i + 1] = a[i];
        }
        //cout << "\n";
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << "\n";
        /*ll sum = 0;
        for (int i = 0; i < n; i++) sum += a[i] * b[i];
        cout << sum << "\n\n";*/
    }
    return 0;
}