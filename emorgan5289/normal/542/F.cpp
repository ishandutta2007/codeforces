#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1005;
vector<int> a[maxn];
priority_queue<int> s, temp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t, q; cin >> t >> q;
        a[t-1].pb(q);
    }
    for (int i = 0; i < m; i++) {
        while (s.size() > 1) {
            int y = s.top(); s.pop();
            temp.push(y+s.top()); s.pop();
        }
        if (s.size() > 0) {
            temp.push(s.top()); s.pop();
        }
        swap(s, temp);
        for (auto& q : a[i])
            s.push(q);
    }
    cout << s.top() << "\n";
}