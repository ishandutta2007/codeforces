#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, a[100005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] <= a[i]) ++cur;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << max(ans,cur);

    return 0;
}