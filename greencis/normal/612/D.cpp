#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,k,x,y;
pii a[2001005];
vector< pii > ans, v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[i+i] = make_pair(x, -1);
        a[i+i+1] = make_pair(y, 1);
    }
    sort(a, a + n + n);
    int balance = 0;
    int prev = -2e9;
    int read = 0;
    for (int i = 0; i < n + n; ++i) {
        if (a[i].second == -1) ++balance;
        else --balance;
        if (balance >= k && !read) {
            prev = a[i].first;
            read = 1;
        } else if (balance < k && read) {
            read = 0;
            v.push_back(make_pair(prev, a[i].first));
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (ans.size() == 0) ans.push_back(v[i]);
        else {
            if (v[i].first == ans.back().second) {
                pii qqq = ans.back();
                ans.pop_back();
                ans.push_back(make_pair(qqq.first, v[i].second));
            } else ans.push_back(v[i]);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;
}