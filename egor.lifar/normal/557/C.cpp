#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


int n;
pair<int, int> l[200000];
int d[200000];
int cnt[201];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i].first;
        l[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    sort(l, l + n);
    int ans = 1000 * 1000 * 1000;
    int sum = 0;
    int sum1 = 0;
    int h = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || l[i].first == l[i + 1].first) {
            sum1 += d[l[i].second];
            h++;
        } else {
            h = 1;
            sum += sum1;
            sum1 = d[l[i].second];
        }
        cnt[d[l[i].second]]--;
        int ans1 = sum;
        int g = max(0, i - h + 1);
        for (int j = 1; j <= 200; j++) {
            ans1 += min(cnt[j], g) * j;
            g -= min(cnt[j], g);
        }   
        //cout << ans1 << endl;
        ans = min(ans, ans1);
    }
    cout << ans << endl;
    return 0;   
}