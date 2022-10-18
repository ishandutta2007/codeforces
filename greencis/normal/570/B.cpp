#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,m,ans,ansc=0,cur;

int main()
{
    cin >> n >> m;
    ans = m;
    cur = m - 1;
    if (cur > ansc) ansc = cur, ans = m - 1;
    cur = n - m;
    if (cur > ansc) ansc = cur, ans = m + 1;
    cout << ans;

    return 0;
}