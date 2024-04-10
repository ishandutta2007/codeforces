#include <iostream>
#define int long long

using namespace std;

int maxRange = 5000000000000000LL;

int calc(int n)
{
    int cnt = 0;
    for (int k = 2; k * k * k <= n; k++) cnt += n / (k * k * k);
    return cnt;
}

int binSearch(int k)
{
    int l = 1, r = maxRange;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (calc(m) >= k) r = m; else l = m+1;
    }
    return (calc(l) == k) ? l : -1;
}

main()
{
    int k; cin >> k;
    cout << binSearch(k) << endl;
}