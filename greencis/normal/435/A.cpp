#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a,cnt,ans;

int main()
{
    cin >> n >> m;
    while (n--) {
        cin >> a;
        if (cnt + a <= m) cnt += a;
        else {
            cnt = a;
            ++ans;
        }
    }
    cout << ans + !!cnt;

    return 0;
}