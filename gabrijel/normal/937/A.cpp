#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        x.push_back(m);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    if (x [0] == 0) cout << x.size() - 1;
    else cout << x.size();
    return 0;
}