#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, b;
ll ans[200105];
pair<ll, ll> a[200105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    ll curt = 0, endtask = -1;
    int idxtask = -1;
    queue< pair<ll, int> > q;
    for (int i = 0; i < n || q.size() || endtask != -1; ) {
        if (endtask != -1 && (i == n || endtask <= a[i].first)) {
            curt = endtask;
            ans[idxtask] = curt;
            endtask = -1, idxtask = -1;
        } else if (i < n) {
            if (endtask == -1) curt = a[i].first;
            if (q.size() < b) q.push(make_pair(a[i].second, i));
            else ans[i] = -1;
            ++i;
        }
        if (endtask == -1) {
            if (q.size()) {
                idxtask = q.front().second;
                endtask = q.front().first + curt;
                q.pop();
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    return 0;
}