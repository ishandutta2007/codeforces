// Codeforces Alpha Round #21
// Problem C -- Stripe 2
#include <iostream>

#define N 100000

using namespace std;

int n, a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for(int i = 0; i != n; ++ i)
        cin >> a[i], sum += a[i];
    if(sum % 3 != 0 || n < 3)
        cout << "0\n";
    else
    {
        int cnt = 0;
        for(int i = 0, tmp = 0; i != n - 1; ++ i)
            cnt += sum - (tmp += a[i]) == sum / 3;
        long long ans = 0;
        for(int i = 0, tmp = 0; i != n - 2; ++ i)
        {
            cnt -= sum - (tmp += a[i]) == sum / 3;
            if(tmp == sum / 3)
                ans += cnt;
        }
        cout << ans << "\n";
    }
    return 0;
}