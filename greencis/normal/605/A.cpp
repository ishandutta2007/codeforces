#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans,x,d[100005];
set<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        set<int>::iterator it = s.lower_bound(-x);
        if (it == s.end() || -*it != x - 1) d[x] = 1;
        else d[x] = d[-*it] + 1;
        ans = max(ans, d[x]);
        s.insert(-x);
    }
    cout << n - ans;

    return 0;
}