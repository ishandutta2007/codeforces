#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int n,a[501505];
map<int,int> mp;
vector<int> ans;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n*n; ++i)
        scanf("%d",&a[i]);
    sort(a,a + n*n);
    reverse(a,a + n*n);
    int curidx = 0;
    while (ans.size() < n && curidx < n*n) {
        if (mp[a[curidx]]) {
            --mp[a[curidx]];
            ++curidx;
            continue;
        }
        ans.push_back(a[curidx]);
        for (int i = 0; i + 1 < ans.size(); ++i)
            mp[gcd(ans[i], ans.back())] += 2;
        ++mp[ans.back()];
    }
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    return 0;
}