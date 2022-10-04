#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const ll LIM = 5e17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    vector <int> cnt(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            if (a[i] == 1) {
                cnt[i] = cnt[i + 1] + 1;
            }
            else {
                cnt[i] = 0;
            }
        }
        else {
            cnt[i] = (a[i] == 1);
        }
    }
    for (int l = 0; l < n; ++l) {
        ll curp = a[l], curs = a[l];
        if (k == 1) ++ans;
        for (int r = l + 1; r < n; ++r) {
            if (a[r] != 1) {
                if (curp > LIM / a[r]) break;
                if ((curs + a[r]) > LIM / k) break;
                curp *= a[r];
                curs += a[r];
                if (curp > k * (curs + (ll)1e5)) break;
                if (curp % curs == 0 && curp / curs == k) ++ans;
            }
            else {
                if (curp <= k * curs) {
                    curs += cnt[r];
                    r += cnt[r] - 1;
                    if ((curs + a[r]) > LIM / k) break;
                }
                else {
                    if (curp > k * (curs + (ll)1e5)) break;
                    int left = -1, right = 1e5;
                    while (right - left > 1) {
                        int mid = (left + right) >> 1;
                        if (curp <= k * (curs + mid)) {
                            right = mid;
                        }
                        else {
                            left = mid;
                        }
                    }
                    if (right > cnt[r]) {
                        curs += cnt[r];
                        r += cnt[r] - 1;
                    }
                    else {
                        r += right - 1;
                        curs += right;
                        if (curp % curs == 0 && curp / curs == k) ++ans;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}