#include <iostream>

using namespace std;

int n, k;
int a[1000000];
int ans = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int q = k - a[i] - a[i-1];
        if (q >= 0) a[i] += q, ans += q;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}