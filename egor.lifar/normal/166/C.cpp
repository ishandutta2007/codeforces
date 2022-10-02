#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n;
int a[501];
int x;
vector<int> ans;


int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans.push_back(a[i]);
    }
    int ans1 = 0;
    sort(ans.begin(), ans.end());
    while (ans[((int)ans.size() + 1) / 2 - 1] != x) {
        ans.push_back(x);
        sort(ans.begin(), ans.end());
        ans1++;
    }
    cout << ans1 << endl;
    return 0;
}