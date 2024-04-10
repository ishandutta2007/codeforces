#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long double q, Min, Max, w;

int main()
{
    cin >> n >> w;
    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    Min = a[0];
    Max = (long double)a[n] / 2.0;
    q = w / 3.0 / (long double)n;
    if (q > Min) q = Min;
    if (q > Max) q = Max;
    q = q * 3 * n;
    cout << setprecision(7) << q;
}