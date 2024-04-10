#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
ll ans = -1;
vector<int> v[3];
int a[200005];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int clr = s[i] == 'O' ? 0 : s[i] == 'W' ? 1 : 2;
        v[clr].push_back(a[i]);
    }
    sort(all(v[0]));
    sort(all(v[1]));
    sort(all(v[2]));
    for (int zzz = 0; zzz < 2; ++zzz) {
        swap(v[1], v[2]);
        if (v[0].size() + v[1].size() < k)
            continue;
        for (int qqq1 = 0; qqq1 < 2; ++qqq1) {
            for (int qqq2 = 0; qqq2 < 2; ++qqq2) {
                ll sum = 0;
                for (int i = 0; i < v[0].size() && i < k; ++i)
                    sum += v[0][i];
                for (int i = 0; i < k - min(k, (int)v[0].size()); ++i)
                    sum += v[1][i];
                int idx1 = min(k, (int)v[0].size()) - 1;
                int idx2 = k - idx1 - 1;
                if (min(k, (int)v[0].size()) > 0 && k - min(k, (int)v[0].size()) > 0)
                    ans = max(ans, sum);
                while (idx1 >= 0 && idx2 < v[1].size()) {
                    sum -= v[0][idx1--];
                    sum += v[1][idx2++];
                    if (idx1 >= 0 && idx2 > 0)
                        ans = max(ans, sum);
                }

                //for (int i = 0; i < v[0].size(); ++i) cerr << v[0][i] << " "; cerr << endl;
               // for (int i = 0; i < v[1].size(); ++i) cerr << v[1][i] << " ";cerr << " = " << ans << endl;

                reverse(all(v[0]));
            }
            reverse(all(v[1]));
        }
    }
    cout << ans;
}