#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll t,s,q,ans;

int main()
{
    cin >> t >> s >> q;
    while (s < t) s *= q, ++ans;
    cout << ans;

    return 0;
}