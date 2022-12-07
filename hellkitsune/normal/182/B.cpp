#include <iostream>

using namespace std;

int main(void)
{
    int d, n, a, cur = 1;
    long long ans = 0;
    cin >> d >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (cur != 1)
            ans += d - cur + 1;
        cur = a + 1;
        if (cur > d)
            cur = 1;
    }
    cout << ans;
    return 0;
}