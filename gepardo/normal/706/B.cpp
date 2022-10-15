#include <iostream>

using namespace std;

int p[1000000];
int q[1000000];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        q[a]++;
    }
    p[0] = q[0];
    for (int i = 1; i < 1000000; i++)
        p[i] = p[i-1] + q[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a; cin >> a;
        cout << ((a >= 1e6) ? n : p[a]) << '\n';
    }
    return 0;
}