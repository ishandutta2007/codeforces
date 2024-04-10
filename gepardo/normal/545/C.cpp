//\
    Codeforces Round 303 (Div. 2) \
    Task C                        \
    24.02.2016                    \
    By alex256
/* :-) :-) (-: (-: */
#include <iostream>
#include <vector>

using namespace std;

main()
{
    int n; cin >> n;
    int res = 0;
    int maxr = -2147483648;
    vector <int> a(n + 3), h(n + 3);
    for (int i = 0; i < n; i++) cin >> a[i] >> h[i];
    a[n] = 2147483647; h[n] = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - h[i] > maxr)
        {
            res++;
            maxr = a[i];
        }
        else if (a[i] + h[i] < a[i + 1])
        {
            res++;
            maxr = a[i] + h[i];
        }
        else maxr = a[i];
    }
    cout << res;
}