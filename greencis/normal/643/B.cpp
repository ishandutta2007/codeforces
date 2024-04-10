#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> path;

int main()
{
    int n, k;
    int a, b, c, d, x;
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    if (k <= n || n == 4)
    {
        cout << -1 << endl;
        return 0;
    }
    path.push_back(a);
    path.push_back(c);
    for (int i = 1; i <= n; i++)
    {
        if (i != a && i != b && i != c && i != d)
        {
            x = i;
            break;
        }
    }
    path.push_back(x);
    path.push_back(d);
    for (int i = 1; i <= n; i++)
    {
        if (i != a && i != b && i != c && i != d && i != x)
            path.push_back(i);
    }
    path.push_back(b);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
    cout << c << " " << a << " " << x << " ";
    for (int i = n - 1; i >= 3; i--)
        cout << path[i] << " ";
    cout << endl;
    return 0;
}