#include <vector>
#include <algorithm>
#include <iostream>
#define INF 2147483000

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q.begin(), q.end());
    for (int i = 0; i < n; i++)
    {
        int Min = INF, Max = 0;
        if (i != 0) Max = q[i] - q[0];
        if (i != (n - 1)) Max = max(Max, q[n - 1] - q[i]);
        if (i != 0) Min = q[i] - q[i - 1];
        if (i != (n - 1)) Min = min(Min, q[i + 1] - q[i]);
        cout << Min << " " << Max << endl;
    }
}